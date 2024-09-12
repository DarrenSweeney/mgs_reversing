#include "tenage.h"

#include "common.h"
#include "chara/snake/sna_init.h"
#include "Bullet/blast.h"
#include "Game/control.h"
#include "Okajima/chafgrnd.h"
#include "Okajima/stngrnd.h"
#include "Weapon/grenade.h"
#include "SD/g_sound.h"
#include "strcode.h"

// the projectile for all types of grenades

typedef struct TenageWork
{
    GV_ACT         actor;
    CONTROL        control;
    OBJECT_NO_ROTS object;
    MATRIX         light[2];
    int            fuse_time;
    int            bounces;
    SVECTOR        step;
    int            type;
    int            field_114_homing_arg3;
    int            do_sound;
    int            side;
    int            control_index;
} TenageWork;

extern short          GM_uBombHoming;
extern TBombFunction  GM_lpfnBombHoming;
extern TBombFunction2 GM_lpfnBombBound;
extern int            GM_GameStatus;
extern int            GM_PlayerStatus_800ABA50;
extern int            dword_800BDD28;
extern Blast_Data     blast_data_8009F4B8[8];
extern SVECTOR        GM_PlayerPosition_800ABA10;
extern SVECTOR        DG_ZeroVector;
extern CONTROL    *tenage_ctrls_800BDD30[16];
extern int            tenage_ctrls_count_800BDD70;

//------------------------------------------------------------------------------

void TenageAct_800699A4(TenageWork *work)
{
    MATRIX rotation;
    SVECTOR vec;
    CONTROL *pCtrl;
#ifdef VR_EXE
    int vy, level;
#endif

    work->control.step = work->step;

    pCtrl = &work->control;

    if (GM_lpfnBombHoming)
    {
        GM_lpfnBombHoming(pCtrl, work->fuse_time, &work->field_114_homing_arg3);
    }

    if ((work->control.mov.pad != 0) || (GM_GameStatus < 0))
    {
        GV_DestroyActor(&work->actor);
        return;
    }

    work->step = work->control.step;

#ifdef VR_EXE
    vy = pCtrl->step.vy;
    pCtrl->step.vy = 0;
#endif

    GM_ActControl(pCtrl);

#ifdef VR_EXE
    vy = vy + pCtrl->mov.vy;
    level = pCtrl->levels[0] + 100;
    if (level >= vy)
    {
        pCtrl->field_57 |= 1;
        vy = level;
    }
    else
    {
        level = pCtrl->levels[1] - 100;
        if (level <= vy)
        {
            pCtrl->field_57 |= 2;
            vy = level;
        }
    }
    pCtrl->mov.vy = vy;
    DG_SetPos2(&pCtrl->mov, &pCtrl->rot);
#endif

    GM_ActObject2((OBJECT *)&work->object);
    DG_GetLightMatrix(&pCtrl->mov, work->light);

    if (!(GM_GameStatus & (STATE_PADRELEASE | STATE_PADDEMO | STATE_DEMO)) && !(GM_PlayerStatus_800ABA50 & PLAYER_PAD_OFF))
    {
        work->fuse_time--;
    }

#ifdef VR_EXE
    else if ((GM_GameStatus & (STATE_PADRELEASE | STATE_PADDEMO)) == STATE_PADDEMO && !(GM_PlayerStatus_800ABA50 & PLAYER_PAD_OFF))
    {
        work->fuse_time--;
    }
#endif

    if (work->fuse_time <= 0 || dword_800BDD28 == 1)
    {
        ReadRotMatrix(&rotation);

        GM_uBombHoming = work->field_114_homing_arg3;

        switch (work->type)
        {
        case GRD_STUN:
            NewStunGrenade_80074B5C(&rotation);
            break;

        case GRD_CHAFF:
            NewChafgrnd_80077264(&rotation);
            break;

        case GRD_TBOMB:
            NewBlast2_8006E0F0(&rotation, &blast_data_8009F4B8[6], work->do_sound, work->side);
            break;

        default:
            NewBlast2_8006E0F0(&rotation, &blast_data_8009F4B8[0], work->do_sound, work->side);
            break;
        }

        sub_8002A258(work->control.map->hzd, &work->control.event);
        GV_DestroyActor(&work->actor);

        GM_uBombHoming = 0;
        return;
    }

    if (pCtrl->field_57 && work->step.vy <= 0)
    {
        work->step.vy = -work->step.vy / 8;
        work->step.vz /= 4;
        work->step.vx /= 4;

        if (work->step.vy < 5)
        {
            work->step = DG_ZeroVector;
        }

        if (++work->bounces < 3)
        {
            if (!GM_lpfnBombBound || !GM_lpfnBombBound(0, pCtrl, &work->field_114_homing_arg3))
            {
                GM_SeSet(&pCtrl->mov, SE_GRENADE_HIT);
            }

            if (work->do_sound != 0)
            {
                GM_SetNoise(128, 12, &pCtrl->mov);
            }
        }
    }
    else
    {
        work->step.vy -= 16;
    }

    if (pCtrl->field_58 > 0 && GM_CheckControlTouches(pCtrl, 300))
    {
        sub_800272E0(pCtrl->field_70[0], &vec);
        DG_ReflectVector(&vec, &work->step, &work->step);

        work->step.vx /= 4;
        work->step.vz /= 4;

        if (++work->bounces < 3)
        {
            if (!GM_lpfnBombBound || !GM_lpfnBombBound(1, pCtrl, &work->field_114_homing_arg3))
            {
                GM_SeSet(&pCtrl->mov, SE_GRENADE_HIT);
            }
        }
    }
}

void TenageDie_80069DBC(TenageWork *work)
{
    GM_FreeControl(&work->control);
    GM_ClearBulName_8004FBE4(work->control.name);
    GM_FreeObject((OBJECT *)&work->object);

    if (work->control_index >= 0)
    {
        tenage_ctrls_800BDD30[work->control_index] = 0;
        tenage_ctrls_count_800BDD70--;
    }
}

int TenageGetNextControl_80069E28(void)
{
    int i;

    for (i = 0; i < (int)(sizeof(tenage_ctrls_800BDD30) / sizeof(CONTROL *)); i++)
    {
        if (tenage_ctrls_800BDD30[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

int TenageGetResources_80069E64(TenageWork *work, SVECTOR *pos, SVECTOR *step, int type, int model, int int_5, int side)
{
    CONTROL *pControl;

    pControl = &work->control;
    if (GM_InitControl(pControl, GM_Next_BulName_8004FBA0(), 0) >= 0)
    {
        if (int_5 != 0)
        {
            GM_ConfigControlHazard(pControl, 100, 50, 50);
        }
        else
        {
            GM_ConfigControlHazard(pControl, 100, -1, -1);
        }
        pControl->field_59 = 4;
        if (side == PLAYER_SIDE)
        {
            pControl->mov = GM_PlayerPosition_800ABA10;
            GM_ConfigControlTrapCheck(pControl);
            GM_ActControl(pControl);
        }
        GM_ConfigControlVector(pControl, pos, (SVECTOR *)&DG_ZeroVector);
        work->step = *step;
        GM_InitObjectNoRots(&work->object, model, WEAPON_FLAG, 0);
        if (work->object.objs)
        {
            DG_SetPos2(&pControl->mov, &pControl->rot);
            DG_PutObjs((work->object).objs);
            GM_ConfigObjectLight((OBJECT *)&work->object, work->light);

            work->control_index = TenageGetNextControl_80069E28();
            if (work->control_index >= 0)
            {
                tenage_ctrls_800BDD30[work->control_index] = pControl;
                pControl->mov.pad = 0;
                tenage_ctrls_count_800BDD70 = tenage_ctrls_count_800BDD70 + 1;
                return 0;
            }
        }
    }
    return -1;
}

GV_ACT *NewTenage_8006A010(SVECTOR *pos, SVECTOR *step, int fuse_time, int type, int model)
{
    TenageWork *work;

    if (tenage_ctrls_count_800BDD70 == 16)
    {
        return NULL;
    }

    work = (TenageWork *)GV_NewActor(5, sizeof(TenageWork));

    if (work)
    {
        GV_SetNamedActor(&work->actor, (TActorFunction)TenageAct_800699A4,
                         (TActorFunction)TenageDie_80069DBC, "tenage.c");

        if (TenageGetResources_80069E64(work, pos, step, type, model, 1, PLAYER_SIDE) < 0)
        {
            GV_DestroyActor(&work->actor);
            return NULL;
        }

        work->fuse_time = fuse_time;
        work->bounces = 0;
        work->type = type;
        work->do_sound = 1;
        work->side = PLAYER_SIDE;
    }

    return &work->actor;
}

GV_ACT *NewTenage2_8006A100(SVECTOR *pos, SVECTOR *step, int fuse_time)
{
    return NewTenage_8006A010(pos, step, fuse_time, GRD_GRENADE, KMD_GRENADE);
}

// enemy's grenades, probably
GV_ACT *NewTenage3_8006A128(SVECTOR *pos, SVECTOR *step, int fuse_time, int type, int model, int do_sound, int player_side)
{
    TenageWork *work;

    work = (TenageWork *)GV_NewActor(6, sizeof(TenageWork));
    if (work)
    {
        GV_SetNamedActor(&work->actor, (TActorFunction)TenageAct_800699A4,
                         (TActorFunction)TenageDie_80069DBC, "tenage.c");

        if (TenageGetResources_80069E64(work, pos, step, type, model, 0, ENEMY_SIDE) < 0)
        {
            GV_DestroyActor(&work->actor);
            return NULL;
        }

        work->fuse_time = fuse_time;
        work->bounces = 0;
        work->type = type;
        work->do_sound = do_sound & 1;
        work->side = player_side & 1;
    }

    return (GV_ACT *)work;
}
