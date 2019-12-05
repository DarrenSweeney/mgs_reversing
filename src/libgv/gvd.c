#include <libsn.h>
#include "actor.h"
#include "system.h"

// sbss ===============================================

int SECTION(".sbss") dword_800AB918;
int SECTION(".sbss") dword_800AB91C;
int SECTION(".sbss") dword_800AB920;
int SECTION(".sbss") dword_800AB924;



// sdata ================================================
int SECTION(".sdata") dword_800AB330 = 0;
int SECTION(".sdata") dword_800AB334 = 0;



extern const char aGvdC[];

// [other_c_sdata]

// ========================================================


extern int dword_8009D460;
extern int dword_800AB928;

int sub_8008BBB0(void);
void sub_800164C8(void);

void GV_Act_80014b60(Actor* pGv)
{
	int tmp;

	dword_800AB330++;
	
	tmp = sub_8008BBB0();
	
	dword_800AB924 = tmp - dword_800AB334;
	dword_800AB334= tmp;

	if (dword_8009D460 == 0)
	{
		// Flip active buffer
    	dword_800AB920 ^= 1;
	}

	if (dword_800AB928 == 0)
	{
    	sub_800164C8();
	}
}

unsigned char SECTION(".heap_80182000") heap_80182000[0x5E000];
unsigned char SECTION(".heap_80117000") heap_80117000[0x6b000];

void System_Init_Heap_0_1_Half_80014BD8(void)
{
    System_init_80015AF4(0, 1, (void*)0x80182000, sizeof(heap_80182000) / 2); // passing heap_80182000 produces addiu instead of ori
    System_init_80015AF4(1, 1, (void*)0x80182000 + sizeof(heap_80182000) / 2 , sizeof(heap_80182000) / 2); // ditto
}

void System_Init_Heap_0_1_Full_80014C28()
{
    System_init_80015AF4(0, 0, (void*)0x80182000, sizeof(heap_80182000)); // passing heap_80182000 produces addiu instead of ori
    System_init_80015AF4(1, 0, 0, 0);
}

extern void mg_printf_8008BBA0(const char*, ...);
extern unsigned char* gResidentTop_800AB940;

extern const char aResidentTopX[];

void GV_Memory_Init_80014C70(void)
{
	System_init_clear_3_heaps_80015AB0();
	System_Init_Heap_0_1_Half_80014BD8();
	System_init_80015AF4(2, 0, (void*)0x80117000, sizeof(heap_80117000)); // passing heap_80117000 produces addiu instead of ori
	mg_printf_8008BBA0(aResidentTopX, gResidentTop_800AB940);
}

extern void sub_800164AC(void);
extern void sub_800167C8(void);

void sub_80014cc8(void)
{
	sub_800164AC();
	sub_800167C8();
}

extern void sub_80015540(void);

void sub_80014cf0(void)
{
	sub_80015540();
	GV_Memory_Init_80014C70();
}

extern void sub_800163B0(void);
extern void GD_ClearFileHandlers_80015434(void);
extern void sub_80015458(void);
extern void sub_80014cc8(void);
extern void sub_800892A8(void*);
extern void sub_80014B34(void);

struct Actor SECTION(".gGVActor_800acbf8") gGVActor_800acbf8;

void GV_StartDaemon_80014d18(void)
{
	GV_ActorList_Init_80014d98();
	sub_800163B0();
	GD_ClearFileHandlers_80015434();
	sub_80015458();
	sub_80014cc8();
	GV_ActorPushBack_800150a8(0, &gGVActor_800acbf8, 0);
	GV_ActorInit_8001514c(&gGVActor_800acbf8, GV_Act_80014b60, 0, "gvd.c"); // sdata
	dword_800AB920 = 0;
	dword_800AB330 = 0;
	sub_800892A8(sub_80014B34);
}

