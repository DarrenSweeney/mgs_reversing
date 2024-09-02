#ifndef _JIRAI_H_
#define _JIRAI_H_

#include "libgv/libgv.h"
#include "Game/control.h"
#include "Game/object.h"
#include "Game/target.h"

// claymore (on ground)

typedef struct JiraiWork
{
    GV_ACT         actor;
    CONTROL        control;
    OBJECT_NO_ROTS body;
    MATRIX         light[2];
    TARGET        *target;
    SVECTOR        field_104_vec;
    short          field_10C;
    short          field_10E;
    int            field_110;
    int            field_114;
    int            field_118;
    int            field_11C;
    int            field_120;
    int            field_124;
    int            field_128;
    int            field_12C;
    int            field_130;
    long           field_134_gcl_arg;
    int            field_138_gcl;
    int            field_13C_idx;
    int            field_140;
    SVECTOR        field_144_vec;
    int            map;
    int            field_150;
#ifdef VR_EXE
    int            field_154;
#endif
} JiraiWork;

GV_ACT *NewJirai_8006B48C(MATRIX *world, HZD_FLR *floor);
GV_ACT *NewScenarioJirai_8006B76C(MATRIX *world, int map);

#endif // _JIRAI_H_
