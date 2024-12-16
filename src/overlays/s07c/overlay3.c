#include "common.h"
#include "Game/camera.h"

short ActTable_800C3310[58] =
{ 
    0x10, 0x11, 0x11, 0x18, 0x10, 0x10, 0x10, 0x10,
    0x18, 0x12, 0x13, 0x1B, 0x1C, 0x1D, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x01, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x14, 0x1A, 0x19, 0x15,
    0x0A, 0x0B, 0x0C, 0x0D, 0x08, 0x16, 0x17, 0x10,
    0x04, 0x04, 0x04, 0x02, 0x17, 0x05, 0x09, 0x05,
    0x0E, 0x0F, 0x0E, 0x0F, 0x06, 0x07, 0x05, 0x09,
    0x05, 0x18
};


unsigned char s07c_dword_800C3384[4] = { 1, 4, 0, 0 };
unsigned char s07c_dword_800C3388[4] = { 255, 4, 0, 0 };

//
SVECTOR s07c_dword_800C338C= { -150, 0, 300 };

//int s07c_dword_800C338C = 0x0000FF6A;
//int s07c_dword_800C3390 = 0x0000012C;

//svector
int s07c_dword_800C3394 = 0x00000000;
int s07c_dword_800C3398 = 0x00000064;

//matrix
int s07c_dword_800C339C = 0x0000FC00;
int s07c_dword_800C33A0 = 0x00000000;
int s07c_dword_800C33A4 = 0x00000000;
int s07c_dword_800C33A8 = 0x00000064;
int s07c_dword_800C33AC = 0x0000FC00;

int s07c_dword_800C33B0 = 0x00000000;

int s07c_dword_800C33B4 = 0x800CB404;
int s07c_dword_800C33B8 = 0x800CB40C;
int s07c_dword_800C33BC = 0x800CB468;
int s07c_dword_800C33C0 = 0x800CB4F0;
int s07c_dword_800C33C4 = 0x800CB414;

int s07c_dword_800C33C8 = 0xFE0C0005;
int s07c_dword_800C33CC = 0x00000050;


const SVECTOR rp_shift_800D4830  = { -200,  100, 900 };
const SVECTOR rp_shift2_800D4838 = { -200, -500, 600 };
const SVECTOR force_800D4840     = { 5, 0, 100 };
const SVECTOR size_800D4848      = { 400, 200, 400 };

const char s07c_aNokezoriend_800D4850[] = " nokezori end!!\n";

const char s07c_dword_800D4864[] = {0x0, 0x0, 0x0, 0x0};