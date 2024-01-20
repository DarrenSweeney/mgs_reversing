#ifndef _SCOPE_H_
#define _SCOPE_H_

#include <SYS/TYPES.H>
#include <LIBGTE.H>
#include <LIBGPU.H>
#include "libgv/libgv.h"
#include "Game/game.h"
#include "Game/control.h"
#include "Game/map.h"

typedef struct ScopeWork
{
  GV_ACT         field_0_scope;
  CONTROL       *field_20_ctrl;
  OBJECT        *field_24_pParent;
  OBJECT_NO_ROTS field_28_obj;
  short          field_4C_saved_packs;
  short          field_4E_saved_raise;
  MAP           *field_50_pMap;
  GV_PAD        *field_54_pOldPad;
  int            field_58;
  short          field_5C_hudDelay; // Adds some delay before showing the HUD of the scope.
  short          field_5E; // Initialized with 2 but apparently never read.
  short          field_60; // Value set to 0 and 1 but apparently never read.
  short          field_62;
  SVECTOR        field_64_vec;
  SVECTOR        field_6C_turn_vec;
  LINE_F2       *field_74_lineF2s[2];
  LINE_F4       *field_7C_lineF4s[2];
  short          field_84[2];
  LINE_F3       *field_88_lineF3s[2];
  LINE_F3       *field_90_lineF3s[2];
  int            field_98_zoomSoundCounter; // Used to play the sound when zooming in/out at a fixed rate.
  int            field_9C_flags;
} ScopeWork;

GV_ACT * NewScope_80063508(CONTROL *pCtrl, OBJECT *pParent, int unused);

#endif // _SCOPE_H_
