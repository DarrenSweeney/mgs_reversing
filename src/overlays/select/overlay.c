#include <stddef.h> // for NULL
#include "charadef.h"
#include "../select1/Game/select.h"

GV_ACT *NewVibEdit_800C47B4(int flags, int perms);

CHARA _StageCharacterEntries[] =
{
    { CHARA_SELECT, NewSelect_800C3434 },
    { CHARA_VIB_EDIT, (NEWCHARA)NewVibEdit_800C47B4 },
    { 0, NULL }
};
