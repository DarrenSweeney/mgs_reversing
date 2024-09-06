#include "charadef.h"
#include "../s16b/Enemy/wall.h"
#include "../s16b/Takabe/shakemdl.h"
#include "../s00a/Okajima/pato_lmp.h"
#include "../s00a/Enemy/command.h"
#include "../s00a/Takabe/wt_view.h"
#include "../s00a/Enemy/watcher.h"
#include "../s00a/Enemy/smoke.h"
#include "../s00a/Thing/emitter.h"
#include "../s00a/Takabe/elevator.h"
#include "../s00a/Okajima/mouse.h"
#include "../s00a/Takabe/rsurface.h"
#include "../s00a/Takabe/cinema.h"
#include "../s16b/Takabe/fadeio.h"
#include "../s00a/Takabe/telop.h"
#include "../d11c/Enemy/demokage.h"
#include "Okajima/bubble_t.h"
#include "Okajima/bubble_p.h"
#include "../d01a/Okajima/blur.h"
#include "Okajima/d_bloods.h"
#include "../d03a/Okajima/red_alrt.h"
#include "../d03a/Okajima/blurpure.h"
#include "../d01a/Kojo/famaslit.h"

void AN_Breath_800C3AA8(MATRIX *matrix);

CHARA _StageCharacterEntries[] = 
{
    { CHARA_OBSTACLE, NewWall_800C3718 },
    { CHARA_SHAKE_MODEL, NewShakemdl_800C54E8 },
    { CHARA_PATO_LAMP, NewPatrolLamp_800D7A2C },
    { CHARA_COMMAND, NewCommand_800D0908 },
    { CHARA_WT_VIEW, NewWaterView_800DBD68 },
    { CHARA_WATCHER, NewSnakeWatcher_800C5034 },
    { CHARA_SMOKE, NewSmoke_800D2BEC },
    { CHARA_EMITTER, NewEmitter_800C3E50 },
    { CHARA_ELEVATOR, NewElevator_800D9F30 },
    { CHARA_MOUSE, NewMouse_800D5234 },
    { CHARA_RSURFACE, NewRippleSurface_800D8244 },
    { CHARA_OBSTACLE, NewWall_800C3718 },
    { CHARA_CINEMA, NewCinemaScreenSet_800DE4D8 },
    { CHARA_FADE_IN_OUT, NewFadeIo_800C42BC },
    { CHARA_FADEIO, NewFadeIo_800C4224 },
    { CHARA_FADEIO_0004, NewFadeIo_800C4224 },
    { CHARA_SHUTER, (NEWCHARA)NewTelop_800DDD7C },
    { CHARA_UNKNOWN_000E, (NEWCHARA)AN_Breath_800C3AA8 },
    { CHARA_DEMOKAGE, (NEWCHARA)NewDemoKage_800C48A4 },
    { CHARA_BUBBLE_T, (NEWCHARA)NewBubbleT_800DA380 },
    { CHARA_BUBBLE_P, (NEWCHARA)NewBubbleP_800D9D94 },
    { CHARA_BLOOD_BL, NewBlur_800CD530 },
    { CHARA_D_BLOODS_002B, (NEWCHARA)NewDBloods_800D5B70 },
    { CHARA_RED_ALERT, (NEWCHARA)NewRedAlert2_800C4E84 },
    { CHARA_RED_ALERT_0038, (NEWCHARA)RedAlert_800C4F48 },
    { CHARA_FALL_SPL, NewBlurPure_800C54D4 },
    { CHARA_FAMASLIT, (NEWCHARA)NewFamaslit_800D06F0 },
    { 0, NULL }
};
