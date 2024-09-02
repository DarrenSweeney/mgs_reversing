#include "tabako.h"
#include "Game/control.h"
#include "libgv/libgv.h"
#include "Game/game.h"
#include "Game/object.h"
#include "Game/linkvarbuf.h"
#include "libdg/libdg.h"
#include "linker.h"
#include "Game/map.h"
#include "psyq.h"
#include <libgpu.h>
#include "Anime/animeconv/anime.h"

// cigarettes

typedef struct _TabakoWork
{
    GV_ACT         actor;
    OBJECT_NO_ROTS object;
    CONTROL       *control;
    OBJECT        *parent;
    int            num_parent;
    DG_PRIM       *prim;
    SVECTOR        vertex;
    RECT           prim_rect;
} TabakoWork;

extern int GM_GameStatus_800AB3CC;
extern int GV_Time_800AB330;
extern int GM_CurrentMap_800AB9B0;

int SECTION(".sbss")    GM_CurrentMap_800AB9B0;
extern PlayerStatusFlag GM_PlayerStatus_800ABA50;

int tabako_dword_8009F2C0 = 0;

void TabakoAct_80061EAC(TabakoWork *work)
{
    OBJECT_NO_ROTS *pObject = &work->object;
    SVECTOR         vec;
    MATRIX          rotMtx;

    GM_SetCurrentMap(work->control->map->index);

    GM_ActObject2_80034B88((OBJECT *)pObject);

    if ((work->parent->objs->flag & DG_FLAG_INVISIBLE) != 0)
    {
        DG_InvisibleObjs(pObject->objs);
        DG_InvisiblePrim(work->prim);
    }
    else
    {
        DG_VisibleObjs(pObject->objs);
        DG_VisiblePrim(work->prim);

        DG_SetPos_8001BC44(&work->prim->world);
        DG_MovePos_8001BD20(&work->vertex);

        ReadRotMatrix(&rotMtx);
        vec.vx = rotMtx.t[0];
        vec.vy = rotMtx.t[1];
        vec.vz = rotMtx.t[2];

        if (GV_Time_800AB330 % 150 >= 121 && tabako_dword_8009F2C0 == 1 &&
            (GM_PlayerStatus_800ABA50 & PLAYER_MOVING) == 0)
        {
            NewAnime_8005E6A4(&vec);
        }
    }

    // Snake, smoking is bad for your health!
    if (!(GV_Time_800AB330 & 63) && GM_SnakeCurrentHealth >= 2)
    {
        GM_SnakeCurrentHealth--;
        GM_GameStatus_800AB3CC |= GAME_HEALTH_UPDATED;
    }
}

void TabakoKill_8006206C(TabakoWork *work)
{
    DG_PRIM *pPrims;

    GM_FreeObject_80034BF8((OBJECT *)&work->object);

    pPrims = work->prim;

    if (pPrims)
    {
        DG_DequeuePrim_800182E0(pPrims);
        DG_FreePrim_8001BC04(pPrims);
    }
}

int TabakoGetResources_800620B4(TabakoWork *work, OBJECT *parent, int num_parent)
{
    OBJECT_NO_ROTS *pObject = &work->object;
    RECT *pRect;
    DG_PRIM *pPrim;
    DG_TEX *pTex;
    int i;
    POLY_FT4 *pPoly;
    int u0, v0, u1, v1;

    GM_InitObjectNoRots_800349B0(pObject, GV_StrCode("cigar"), 109, 0);

    if (!pObject->objs)
    {
        return -1;
    }

    GM_ConfigObjectRoot_80034C5C((OBJECT *)pObject, parent, num_parent);

    pRect = &work->prim_rect;
    pRect->x = pRect->y = 6;
    pRect->w = pRect->h = 12;

    work->prim = pPrim = DG_GetPrim(0x412, 1, 0, &work->vertex, pRect);

    if (!pPrim)
    {
        return -1;
    }

    work->vertex.vx = 37;
    work->vertex.vy = -55;
    work->vertex.vz = 140;

    pPrim->field_2E_k500 = 250;
    pTex = DG_GetTexture_8001D830(GV_StrCode("rcm_l"));

    for (i = 0; i < 2; i++)
    {
        pPoly = &pPrim->packs[i]->poly_ft4;

        LSTORE(0x808080, &pPoly->r0);

        setPolyFT4(pPoly);
        setSemiTrans(pPoly, 1);

        u0 = pTex->off_x;
        u1 = u0 + pTex->w;

        v0 = pTex->off_y;
        v1 = v0 + pTex->h;

        pPoly->u0 = u0;
        pPoly->v0 = v0;

        pPoly->u1 = u1;
        pPoly->v1 = v0;

        pPoly->u2 = u0;
        pPoly->v2 = v1;

        pPoly->u3 = u1;
        pPoly->v3 = v1;

        pPoly->tpage = pTex->tpage;
        pPoly->clut = pTex->clut;
    }

    work->prim->root = work->object.objs->root;
    return 0;
}

GV_ACT * NewTabako_80062274(CONTROL *control, OBJECT *parent, int num_parent)
{
    TabakoWork *work = (TabakoWork *)GV_NewActor(6, sizeof(TabakoWork));

    if (work)
    {
        GV_SetNamedActor(&work->actor, (TActorFunction)TabakoAct_80061EAC,
                         (TActorFunction)TabakoKill_8006206C, "tabako.c");

        if (TabakoGetResources_800620B4(work, parent, num_parent) < 0)
        {
            GV_DestroyActor(&work->actor);
            return 0;
        }

        work->control = control;
        work->parent = parent;
        work->num_parent = num_parent;
    }

    return &work->actor;
}
