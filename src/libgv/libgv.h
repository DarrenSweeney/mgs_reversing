/**
 * This file defines the core structures, enumerations, and function prototypes used in the LibGV library,
 * It provides essential services for managing game actors, memory allocation, message handling,
 * input processing, and mathematical operations.
 *
 * Key Components:
 * - Actor Management: Defines structures and functions for creating, updating, and managing game actors
 * - Memory Management: Provides dynamic memory allocation and heap management to handle the game's resource
 * - Message Handling: Implements a messaging system for communication between different game components
 * - Input Processing: Manages gamepad inputs.
 * - Cache System: Handles file caching and loading for game resources by hashing file names
 * - Heap Management: Manages memory allocation and deallocation using a heap-based system
 * - Mathematical Operations: Offers functions for vector calculations and other mathematical tasks
 *   needed for game physics and transformations.
 */

#ifndef LIBGV_H_
#define LIBGV_H_

#include "linker.h"
#include "mts/mts_new.h"
#include <sys/types.h>
#include <libgte.h>
#include <libetc.h>

struct GV_ACT;

typedef void (*TActorFunction)(struct GV_ACT *);
typedef void (*TActorFreeFunction)(void *);

/**
 * @brief Linked list of game actors.
 * A game actor is an entity with a name and an update function.
 */
typedef struct GV_ACT
{
    struct GV_ACT     *prev;
    struct GV_ACT     *next;
    TActorFunction     act;         // update callback
    TActorFunction     die;         // shutdown callback
    TActorFreeFunction free;        // free callback
    const char        *filename;    // source filename
    int                field_18;
    int                field_1C;
} GV_ACT;

struct ActorList    // private to libgv/actor.c
{
    GV_ACT first;
    GV_ACT last;
    short  pause;
    short  kill;
};

#define ACTOR_LIST_COUNT 9

struct PauseKill    // private to libgv/actor.c
{
    short pause;
    short kill;
};

typedef struct
{
    int   id;
    void *ptr;
} GV_CACHE_TAG;

typedef struct
{
    unsigned short address;
    unsigned short _len;
    unsigned short message[7];
    unsigned short message_len;
} GV_MSG; // from mem leak

typedef struct
{
    int    field_0_count;
    GV_MSG field_4_msgs[16];
} GV_Messages;

// has to be in a struct to match
typedef struct CacheSystems
{
    GV_CACHE_TAG tags[128];
} CacheSystems;

#define MAX_UNITS 512
#define GV_NORMAL_MEMORY 2 // seen from leaks

enum GV_MEMORY_STATE
{
    GV_MEMORY_STATE_FREE = 0,
    GV_MEMORY_STATE_VOID = 1,
    GV_MEMORY_STATE_USED = 2,
};

typedef union AllocType {
    int    type;
    void **addr;
} AllocType;

typedef struct GV_MemoryAllocation
{
    void        *mPDataStart;
    unsigned int mAllocType; // might be union if its > 2 its void** ?
} GV_MemoryAllocation;

enum GV_HEAP_FLAG
{
    GV_HEAP_FLAG_DYNAMIC = 1,
    GV_HEAP_FLAG_VOIDED = 2,
    GV_HEAP_FLAG_FAILED = 4,
};

typedef struct GV_Heap
{
    int                 mFlags;
    void               *mStartAddr;
    void               *mEndAddr;
    int                 mUnitsCount;
    GV_MemoryAllocation mAllocs[MAX_UNITS];
} GV_Heap;

typedef struct
{
    unsigned short status;
    unsigned short press;
    unsigned short release;
    unsigned short quick;
    short          dir;

    short         analog;
    unsigned char right_dx;
    unsigned char right_dy;
    unsigned char left_dx;
    unsigned char left_dy;
} GV_PAD;

enum
{
    GV_PAD_DIGITAL = 0,
    GV_PAD_ANAJOY = 1,
    GV_PAD_ANALOG = 2
};

// TODO: typedef enum and use type in GV_PAD?
enum
{
    PAD_UP = PADLup,        //  0x1000
    PAD_DOWN = PADLdown,    //  0x4000
    PAD_LEFT = PADLleft,    //  0x8000
    PAD_RIGHT = PADLright,  //  0x2000
    PAD_TRIANGLE = PADRup,  //  0x0010
    PAD_CROSS = PADRdown,   //  0x0040
    PAD_SQUARE = PADRleft,  //  0x0080
    PAD_CIRCLE = PADRright, //  0x0020
    PAD_L1 = PADL1,         //  0x0004
    PAD_L2 = PADL2,         //  0x0001
    PAD_R1 = PADR1,         //  0x0008
    PAD_R2 = PADR2,         //  0x0002
    PAD_START = PADstart,   //  0x0800
    PAD_SELECT = PADselect, //  0x0100
};

enum GV_CACHE_REGION
{
    GV_NO_CACHE,
    GV_NORMAL_CACHE,
    GV_RESIDENT_CACHE,
};

typedef int (*TFileExtHandler)(unsigned char *pFileData, int fileNameHashed);

/* gvd.c */
void GV_StartDaemon_80014D18(void);
void GV_ResetSystem_80014CC8(void);

/* actor.c */
void    GV_ExecActorSystem_80014F88(void);
GV_ACT *GV_NewActor_800150E4(int level, int memSize);
void    GV_InitActorSystem_80014D98(void);
void    GV_DestroyActorSystem_80015010(int level);
void    GV_InitActor_800150A8(int level, GV_ACT *actor, TActorFreeFunction free_func);
void    GV_SetNamedActor_8001514C(GV_ACT *actor, TActorFunction act_func, TActorFunction die_func,
                                  const char *filename);
void    GV_DestroyActor_800151C8(GV_ACT *actor);
void    GV_DestroyOtherActor_800151D8(GV_ACT *actor);
void    GV_DestroyActorQuick_80015164(GV_ACT *actor);

/* cache.c */
void  GV_InitCacheSystem_80015458(void);
void  GV_InitLoader_80015434(void);
void  GV_FreeCacheSystem_80015540(void);
int   GV_CacheID_800152DC(int strcode, int extID);
void  GV_SetLoader_80015418(int fileExtChar, TFileExtHandler pFn);
int   GV_SetCache_800153C0(int id, void *buf);
void *GV_GetCache_8001538C(int id);
int   GV_CacheID2_800152FC(const char *fileName, int extID);
void  GV_ResidentFileCache_80015484(void);
int   GV_LoadInit_800155BC(void *pData, int id, int region);

/* memory.c */
void  GV_InitMemorySystemAll_80015AB0();
void  GV_InitMemorySystem_80015AF4(int, int, void *, int);
void  GV_ResetMemory_80014CF0(void);
void *GV_AllocMemory_80015EB8(int, int);
void *GV_AllocMemory2_80015ED8(int, int, void **);
void  GV_FreeMemory_80015FD0(int, void *);
void  GV_FreeMemory2_80016078(int, void **);
void  GV_ClearMemorySystem_80015B4C(int);
void  GV_CheckMemorySystem_80015BF8(int);
void  GV_DumpMemorySystem_80015D48(int);
void  GV_CopyMemory_800160D8(void *, void *, int);
void  GV_ZeroMemory_8001619C(void *, int);
void *GV_Malloc_8001620C(int);
void  GV_Free_80016230(void *);
void  GV_DelayedFree_80016254(void *);
void  GV_ResidentHeapReset_800163B0(void);
void *GV_ResizeMemory_8001630C(int which, void *addr, int size);

void *GV_GetMaxFreeMemory_8001627C(int which);
void *GV_SplitMemory_80018FA4(int which, void *addr, int size);

void  GV_InitResidentMemory(void); // unsure what function this maps to
void *GV_AllocResidentMemory_800163D8(long size);

/* message.c */
void GV_InitMessageSystem_800164AC();
void GV_ClearMessageSystem_800164C8(void);
int  GV_SendMessage_80016504(GV_MSG *send);
int  GV_ReceiveMessage_80016620(int msg_type, GV_MSG **ppFound);

/* pad.c */
void GV_InitPadSystem_800167C8(void);
void GV_UpdatePadSystem_8001682C(void);
void GV_OriginPadSystem_80016C78(int);
int  GV_GetPadOrigin_80016C84(void);
int  GV_GetPadDirNoPadOrg_80016C90(unsigned int);

/* strcode.c */
int GV_StrCode_80016CCC(const char *string);

/* math.c, math_near.c */
void         GV_SubVec3_80016D40(SVECTOR *vec1, SVECTOR *vec2, SVECTOR *dst);
int          GV_VecLen3_80016D80(SVECTOR *vec);
int          GV_VecDir2_80016EF8(SVECTOR *vec);
void         GV_AddVec3_80016D00(SVECTOR *vec1, SVECTOR *vec2, SVECTOR *dst);
void         GV_LenVec3_80016DDC(SVECTOR *in, SVECTOR *out, int denom, int num);
int          GV_DiffVec3_80016E84(SVECTOR *vec1, SVECTOR *vec2);
int          GV_NearExp2_80026384(int from, int to);
int          GV_NearExp4_800263B0(int from, int to);
int          GV_NearExp8_800263E4(int from, int to);
void         GV_NearExp2V_8002667C(short *from, short *to, int count);
void         GV_NearExp4V_800266D4(short *from, short *to, int count);
void         GV_NearExp8V_80026734(short *from, short *to, int count);
int          GV_NearExp2P_80026554(int from, int to);
int          GV_NearExp4P_80026554(int from, int to);
int          GV_NearExp8P_80026554(int from, int to);
void         GV_NearExp2PV_80026924(short *from, short *to, int count);
void         GV_NearExp4PV_800269A0(short *from, short *to, int count);
void         GV_NearExp8PV_80026A24(short *from, short *to, int count);
int          GV_DiffDirS_8001704C(int param_1, int param_2);
int          GV_DiffDirAbs_8001706C(int a1, int a2);
int          GV_RandU_80017090(unsigned int input);
int          GV_RandS_800170BC(int input);
void         GV_DirVec2_80016F24(int a1, int a2, SVECTOR *a3);
int          GV_NearDiffP_80026418(int from, int to);
int          sub_80026440(int from, int to, int range);
int          sub_8002646C(int from, int to, int range);
void         GV_DirVec3_80016FA0(SVECTOR *pSrcVec, int param_2, SVECTOR *pDstVec);
unsigned int GV_DiffDirU_80017040(int param_1, int param_2);
void         sub_8002ECE4(SVECTOR *param_1, SVECTOR *param_2, SVECTOR *param_3);
void         CopyVectorFromScratchpad_80029360(SVECTOR *vec_1, SVECTOR *vec_2);

void         GV_NearTimeSV_800268AC(short *from, short *to, int interp, int count);
void         GV_NearTimePV_80026BC4(short *from, short *to, int interp, int count);

int          GV_NearTime_800264B0(int from, int to, int interp);
void         GV_SetPacketTempMemory_80014C28(void);
void         GV_ResetPacketMemory_80014BD8(void);

void sub_8002751C(SVECTOR *svec1, SVECTOR *svec2);
int  sub_80027BF8(SVECTOR *param_1);

static inline short FP_Extend(short value)
{
    value &= 0xfff;

    if (value > 2048)
    {
        value -= 4096;
    }

    return value;
}

static inline int FP_Extend2(int value)
{
    value &= 0xfff;

    if (value >= 2048)
    {
        value -= 4096;
    }

    return value;
}

static inline int FP_ExtendN(int value)
{
    value |= 0xf000;

    if (value < -2048)
    {
        value += 4096;
    }

    return value;
}

static inline int FP_Subtract(int fp, int toSub)
{
    short var_a0 = fp - toSub;
    var_a0 &= 0xfff;
    if (var_a0 > 2048)
    {
        var_a0 -= 4096;
    }
    return var_a0;
}

static inline int FP_Subtract_2(int a, int b)
{
    int value = a - b;

    if (value >= 0)
    {
        value &= 0xFFF;

        if (value >= 2048)
        {
            value -= 4096;
        }
    }
    else
    {
        value |= 0xF000;

        if (value < -2048)
        {
            value += 4096;
        }
    }

    return value;
}

typedef struct GV_Vec
{
    short x;
    short y;
    short z;
} GV_Vec;

#endif // LIBGV_H
