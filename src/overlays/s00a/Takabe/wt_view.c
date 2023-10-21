#include "libdg/libdg.h"
#include "libgcl/libgcl.h"
#include "libgv/libgv.h"

typedef struct _WaterViewPrims
{
    DR_TPAGE tpage[4];
    char     pad[0x18];
    SPRT     sprt[2][122];
    SPRT     sprt2[2][122];
    TILE     tile[4];
    TILE     tile2[2];
} WaterViewPrims;

typedef struct _WaterViewWork
{
    GV_ACT          actor;
    int             map;
    int             name;
    SVECTOR         f28;
    SVECTOR         f30;
    WaterViewPrims *prims;
    CVECTOR         color;
    int             f40;
    char            pad2[0x4];
    int             f48;
} WaterViewWork;

extern int     GV_Clock_800AB920;
extern int     GV_PauseLevel_800AB928;
extern DG_CHNL DG_Chanls_800B1800[3];

extern const char sWtViewC[]; // = "wt_view.c"

// PsyQ
void s00a_800DFB1C(SPRT *);
void s00a_800DFB3C(TILE *);
int  s00a_800DFB9C(void *prim, int, int);

int  WaterView_800DBEB8(WaterViewWork *work);
void WaterView_800DC0CC(void);
void WaterView_800DC128(WaterViewWork *work);

static short wt_view_sin_table[32];

#define EXEC_LEVEL 3

void WaterView_800DB800(SPRT *sa, SPRT *sb, CVECTOR *color)
{
    SPRT sprt;
    int  i;

    s00a_800DFB1C(&sprt);

    sprt.x0 = -160;
    sprt.y0 = -112;
    sprt.w = 160;
    sprt.h = 2;
    sprt.u0 = 0;
    sprt.v0 = 0;

    sprt.r0 = color->r;
    sprt.g0 = color->g;
    sprt.b0 = color->b;

    for (i = 122; i >= 0; i--)
    {
        *sa = sprt;
        *sb = *sa;

        sa++;
        sb++;
    }
}

void WaterView_800DB8F4(SPRT *sa, SPRT *sb, CVECTOR *color)
{
    SPRT sprt;
    int  i;

    s00a_800DFB1C(&sprt);

    sprt.x0 = 0;
    sprt.y0 = -112;
    sprt.w = 160;
    sprt.h = 2;
    sprt.u0 = 32;
    sprt.v0 = 0;

    sprt.r0 = color->r;
    sprt.g0 = color->g;
    sprt.b0 = color->b;

    for (i = 122; i >= 0; i--)
    {
        *sa = sprt;
        *sb = *sa;

        sa++;
        sb++;
    }
}

static inline int WaterViewActHelper_800DB9E8(WaterViewWork *work, short x, short y, short z)
{
    if ((x > work->f28.vx) && (x < work->f30.vx) &&
        (y > work->f28.vy) && (y < work->f30.vy) &&
        (z > work->f28.vz) && (z < work->f30.vz))
    {
        return 1;
    }

    return 0;
}

void WaterViewAct_800DB9E8(WaterViewWork *work)
{
    SVECTOR  sp10;
    u_long  *ot;
    SVECTOR *vec;
    MATRIX  *eye;
    short    x, y, z;
    TILE    *tile;
    void    *prim2;

    ot = (u_long *)DG_ChanlOTag(0);

    vec = &sp10;
    eye = &DG_Chanls_800B1800[1].field_30_eye;

    vec->vx = x = eye->t[0];
    vec->vy = y = eye->t[1];
    vec->vz = z = eye->t[2];

    if (WaterViewActHelper_800DB9E8(work, x, y, z) != work->f40)
    {
        if (work->f40 != 0)
        {
            GV_DelayedFree_80016254(work->prims);
            work->f40 = 0;
        }
        else if (!WaterView_800DBEB8(work))
        {
            work->f40 = 1;
        }
    }

    if (work->f40 != 0)
    {
        WaterView_800DC128(work);

        tile = &work->prims->tile2[GV_Clock_800AB920];
        addPrim(&ot[0xFF], tile);

        prim2 = (char *)work->prims + 0x20 + GV_Clock_800AB920 * 12;
        s00a_800DFB9C(prim2, 0, 1);
        addPrim(&ot[0xFF], prim2);

        if (GV_PauseLevel_800AB928 == 0)
        {
            work->f48++;
        }
    }
}

void WaterViewDie_800DBBF0(WaterViewWork *work)
{
    if (work->prims)
    {
        GV_DelayedFree_80016254(work->prims);
    }
}

int WaterViewGetResources_800DBC20(WaterViewWork *work, int unused, int unused2)
{
    work->color.r = 100;
    work->color.g = 128;
    work->color.b = 120;

    if (GCL_GetOption_80020968('b'))
    {
        GCL_StrToSV_80020A14(GCL_Get_Param_Result_80020AA4(), &work->f28);
        GCL_StrToSV_80020A14(GCL_Get_Param_Result_80020AA4(), &work->f30);
    }

    if (GCL_GetOption_80020968('c'))
    {
        work->color.r = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
        work->color.g = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
        work->color.b = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
    }

    WaterView_800DC0CC();

    work->f40 = 0;
    return 0;
}

int WaterViewGetResources_800DBCE4(WaterViewWork *work, SVECTOR *arg1, CVECTOR *color)
{
    work->f28 = arg1[0];
    work->f30 = arg1[1];

    work->color = *color;

    WaterView_800DC0CC();

    work->f40 = 0;
    return 0;
}

GV_ACT * NewWaterView_800DBD68(int name, int where)
{
    WaterViewWork *work;

    work = (WaterViewWork *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(WaterViewWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)WaterViewAct_800DB9E8, (TActorFunction)WaterViewDie_800DBBF0, sWtViewC);

        if (WaterViewGetResources_800DBC20(work, name, where) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }

        work->map = where;
        work->name = name;
    }

    return &work->actor;
}

GV_ACT * NewWaterView_800DBE04(int name, int where, SVECTOR *arg2, CVECTOR *color)
{
    WaterViewWork *work;

    work = (WaterViewWork *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(WaterViewWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)WaterViewAct_800DB9E8, (TActorFunction)WaterViewDie_800DBBF0, sWtViewC);

        if (WaterViewGetResources_800DBCE4(work, arg2, color) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }

        work->map = where;
        work->name = name;
    }

    return &work->actor;
}

int WaterView_800DBEB8(WaterViewWork *work)
{
    WaterViewPrims *prims;
    TILE           *tile;
    TILE           *tile2;

    prims = GV_Malloc_8001620C(sizeof(WaterViewPrims));
    work->prims = prims;
    if (!prims)
    {
        return -1;
    }

    WaterView_800DB800(prims->sprt[0], prims->sprt[1], &work->color);
    WaterView_800DB8F4(prims->sprt2[0], prims->sprt2[1], &work->color);

    SetDrawTPage(&prims->tpage[0], 0, 1, GetTPage(2, 0, 0, 0));
    SetDrawTPage(&prims->tpage[1], 0, 1, GetTPage(2, 0, 320, 0));
    SetDrawTPage(&prims->tpage[2], 0, 1, GetTPage(2, 0, 128, 0));
    SetDrawTPage(&prims->tpage[3], 0, 1, GetTPage(2, 0, 448, 0));

    tile = &work->prims->tile[0];
    s00a_800DFB3C(tile);

    tile->x0 = -160;
    tile->w = 320;
    tile->h = 6;

    tile->r0 = 0;
    tile->g0 = 0;
    tile->b0 = 0;

    tile[1] = tile[0];

    tile[0].y0 = -112;
    tile[1].y0 = 106;

    tile[2] = tile[0];
    tile[3] = tile[1];

    tile2 = &work->prims->tile2[0];
    setTile(tile2);

    tile2->x0 = -160;
    tile2->y0 = -112;
    tile2->w = 320;
    tile2->h = 224;

    tile2->r0 = 0;
    tile2->g0 = 0;
    tile2->b0 = 0;

    tile2[1] = tile2[0];

    return 0;
}

void WaterView_800DC0CC(void)
{
    int i;

    for (i = 0; i < 32; i++)
    {
        wt_view_sin_table[i] = rsin(i * 128) / 1024;
    }
}

#pragma INCLUDE_ASM("asm/overlays/s00a/WaterView_800DC128.s")