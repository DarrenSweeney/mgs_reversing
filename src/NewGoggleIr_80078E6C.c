#include "actor.h"
#include "game.h"

extern char aGoggleirC[]; // = "goggleir.c"

typedef struct _Actor_GoggleIr
{
    Actor field_0_actor;
    OBJECT f20_obj;
    int f44;
    OBJECT *parent_object;
    int num_parent;
    int f50;
    short f54;
    short f56;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
} Actor_GoggleIr;

extern int goggleir_act_80078BE0(int a1);
extern int goggleir_kill_80078CE4(int a1);
extern void GV_DestroyActor_800151C8(struct Actor *pActor);
extern int  goggleir_loader_80078D8C(Actor_GoggleIr *a1, OBJECT *a2);

STATIC_ASSERT_SIZE(Actor_GoggleIr, 0x6C);

Actor_GoggleIr *NewGoggleIr_80078E6C(int a1, OBJECT *parent_obj)
{
    Actor_GoggleIr *goggleir_actor = (Actor_GoggleIr*)GV_NewActor_800150E4(6, sizeof(Actor_GoggleIr));

    if (goggleir_actor)
    {
        GV_SetNamedActor_8001514C(
            &goggleir_actor->field_0_actor,
            (TActorFunction)&goggleir_act_80078BE0,
            (TActorFunction)&goggleir_kill_80078CE4,
            aGoggleirC);

        if (goggleir_loader_80078D8C(goggleir_actor, parent_obj) < 0)
        {
            GV_DestroyActor_800151C8(&goggleir_actor->field_0_actor);
            return 0;
        }
    }
    
    goggleir_actor->f44 = a1;
    goggleir_actor->f50 = 0;
    
    return goggleir_actor;
}
