#ifndef _FAMAS_H_
#define _FAMAS_H_

#include "Game/game.h"
#include "Game/control.h"
#include "libgv/libgv.h"

typedef struct _FamasWork
{
    GV_ACT         actor;
    OBJECT_NO_ROTS obj;
    CONTROL       *control;
    OBJECT        *parent_object;
    int            num_parent;
    int           *field_50_pFlags;
    int            field_54;
    int            field_58_counter;
    int            field_5C_mp5;
} FamasWork;

GV_ACT *NewFAMAS_80066374(CONTROL *a1, OBJECT *a2, int num_parent, unsigned int* a4, int side);

#endif // _FAMAS_H_
