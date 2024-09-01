#include "hash.h"
#include "libgcl.h"

// #define STATIC static
#define STATIC

int SECTION(".sbss") scenerio_code;
int SECTION(".sbss") dword_800AB994;

STATIC int GCL_InitFunc(unsigned char *top, int id)
{
    if (id == scenerio_code)
    {
        GCL_LoadScript(top);
    }
    return 1;
}

void GCL_ChangeSenerioCode(int demo_flag)
{
    scenerio_code = (demo_flag == 1)
        ? GCL_StrHash(HASH_demo)        // 0x006a242
        : GCL_StrHash(HASH_scenerio);   // 0x006ea54
}

void GCL_StartDaemon(void)
{
    GCL_ParseInit();
    GCL_InitVar();
    GCL_InitBasicCommands();
    GV_SetLoader('g', GCL_InitFunc);
    GCL_ChangeSenerioCode(0);
}

void GCL_ResetSystem(void)
{
    /* do nothing */
}
