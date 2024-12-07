#ifndef _GOGGLEIR_H
#define _GOGGLEIR_H

#include "libgv/libgv.h"
#include "Game/game.h"
#include "Game/control.h"

// thermal goggles (screen effect)

typedef struct GoggleIrWork
{
    GV_ACT         actor;
    OBJECT_NO_ROTS field_20_obj;
    CONTROL       *control;
    OBJECT        *field_48_pParent;
    int            field_4C_head_hidden;
    int            field_50;
    GV_ACT        *field_54_pScn_mask; // thermal goggles screen effect
    GV_ACT        *field_58_pGglmng;
    int            field_5C;
    int            field_60;
    GV_ACT        *field_64_pGglmng;
    short          field_68_savedNPacks;
    short          field_6A_saved_raise;
} GoggleIrWork;

STATIC_ASSERT(sizeof(GoggleIrWork) == 0x6C, "sizeof(GoggleIrWork) is wrong!");

GV_ACT *NewGoggleManager(int type);
GV_ACT *NewGoggleIr_80078E6C(CONTROL *pCtrl, OBJECT *parent_obj, int unused);

#endif // _GOGGLEIR_H
