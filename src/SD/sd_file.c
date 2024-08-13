#include "SD/sound.h"
#include "SD/sd_incl.h"
#include "libfs/libfs.h"
#include "psyq.h"
#include "unknown.h"

extern char            *cdload_buf_800BF010;
extern int              se_fp_800BF014;
extern int              spu_load_offset_800BF140;
extern int              sng_status_800BF158;
extern unsigned int     gStreamVol_800BF15C;
extern unsigned int     gStr_FadeOut1_800BF16C;
extern int              dword_800BF1DC;
extern WAVE_W          *voice_tbl_800BF1E0;
extern int              dword_800BF26C;
extern int              wave_unload_size_800BF274;
extern unsigned int     dword_800BF27C;
extern int              se_load_code_800BF28C;
extern int              wave_data_800BF294;
extern int              dword_800C0418;
extern unsigned char   *sd_sng_data_800C0420;
extern int              dword_800C04EC;
extern int              gStream_800C04F0;
extern int              dword_800C04F4;
extern unsigned int     sng_status_800C04F8;
extern int              dword_800C0500;
extern char            *wave_load_ptr_800C0508;
extern int              sound_mono_fg_800C050C;
extern unsigned char   *se_exp_table_800C0520;
extern int              wave_load_code_800C0528;
extern int              spu_wave_start_ptr_800C052C;
extern unsigned char    byte_800C056C;
extern int              wave_save_code_800C0578;
extern int              dword_800C0650;
extern unsigned int     gStr_fadeout_2_800C0584;

void nullsub_7_80081A10(int *arg0, int arg1, int arg2); /* in sd_main.c */
void sng_off_80087E2C(void); /* in sd_ioset.c */

int SD_LoadSeFile_8008341C(void)
{
    if (se_fp_800BF014)
    {
        printf("ERROR:SE File Already Opened.\n");
        SD_8008395C(se_fp_800BF014, 4);
        se_fp_800BF014 = 0;
    }
    se_fp_800BF014 = SD_SongLoadData_8008394C(se_load_code_800BF28C, 4);
    if (se_fp_800BF014 < 0)
    {
        se_fp_800BF014 = 0;
        printf("LoadSeFile:File Open Error(%x)\n", se_load_code_800BF28C);
        nullsub_7_80081A10(&dword_800C0500, -4, se_load_code_800BF28C); // TODO: Not sure if last arg exists
        return -1;
    }
    else
    {
        SD_80083954(se_fp_800BF014, se_exp_table_800C0520, 0x2800);
        SD_8008395C(se_fp_800BF014, 4);
        se_load_code_800BF28C = 0;
        se_fp_800BF014 = 0;
        return 0;
    }
}

int SD_LoadWaveFile_800834FC(void)
{
    unsigned int offset;
    unsigned int size;
    char        *dst;

    if (wave_data_800BF294 != 0)
    {
        printf("ERROR:Wave File Already Opened.\n");
        SD_8008395C(wave_data_800BF294, 2);
        wave_data_800BF294 = 0;
    }

    wave_data_800BF294 = SD_SongLoadData_8008394C(wave_load_code_800C0528, 2);

    if (wave_data_800BF294 < 0)
    {
        wave_data_800BF294 = 0;
        printf("LoadWaveFile:File Open Error(%x)\n", wave_load_code_800C0528);
        nullsub_7_80081A10(&dword_800C0500, -4, wave_load_code_800C0528);
        wave_load_code_800C0528 = 0;
        return -1;
    }

    SD_80083954(wave_data_800BF294, cdload_buf_800BF010, 0x18000);
    byte_800C056C = 0x4F;

    offset = cdload_buf_800BF010[0] << 24;
    offset |= cdload_buf_800BF010[1] << 16;
    offset |= cdload_buf_800BF010[2] << 8;
    offset |= cdload_buf_800BF010[3];

    size = cdload_buf_800BF010[4] << 24;
    size |= cdload_buf_800BF010[5] << 16;
    size |= cdload_buf_800BF010[6] << 8;
    size |= cdload_buf_800BF010[7];

    printf("SUP OFFSET=%x:SIZE=%x\n", offset, size);

    wave_load_ptr_800C0508 = cdload_buf_800BF010 + 16;
    dst = (char *)voice_tbl_800BF1E0 + offset;
    memcpy(dst, wave_load_ptr_800C0508, size);

    printf("    SRC=%x:DST=%x\n", (unsigned int)wave_load_ptr_800C0508, (unsigned int)dst);

    wave_load_ptr_800C0508 += size;

    spu_load_offset_800BF140 = wave_load_ptr_800C0508[0] << 24;
    spu_load_offset_800BF140 |= wave_load_ptr_800C0508[1] << 16;
    spu_load_offset_800BF140 |= wave_load_ptr_800C0508[2] << 8;
    spu_load_offset_800BF140 |= wave_load_ptr_800C0508[3];

    wave_unload_size_800BF274 = wave_load_ptr_800C0508[4] << 24;
    wave_unload_size_800BF274 |= wave_load_ptr_800C0508[5] << 16;
    wave_unload_size_800BF274 |= wave_load_ptr_800C0508[6] << 8;
    wave_unload_size_800BF274 |= wave_load_ptr_800C0508[7];

    printf("BIN OFFSET=%x\n", (unsigned int)wave_load_ptr_800C0508);
    printf("SPU OFFSET=%x:SIZE=%x\n",
                         spu_load_offset_800BF140, wave_unload_size_800BF274);

    wave_load_ptr_800C0508 += 16;

    if (wave_unload_size_800BF274 > (0x17FE0 - size))
    {
        dword_800C0650 = 0x17FE0 - size;
    }
    else
    {
        dword_800C0650 = wave_unload_size_800BF274;
    }

    wave_unload_size_800BF274 -= dword_800C0650;
    wave_save_code_800C0578 = wave_load_code_800C0528;
    return 0;
}

void sub_80083804(void)
{
    int temp;

    if (wave_unload_size_800BF274 > 0x18000U)
    {
        SD_80083954(wave_data_800BF294, cdload_buf_800BF010, 0x18000);
        dword_800C0650 = 0x18000;
        dword_800BF27C = 2;
        wave_load_ptr_800C0508 = cdload_buf_800BF010;
        wave_unload_size_800BF274 -= 0x18000U;
        return;
    }
    if (wave_unload_size_800BF274 != 0)
    {
        SD_80083954(wave_data_800BF294, cdload_buf_800BF010, wave_unload_size_800BF274);
        temp = wave_unload_size_800BF274;
        wave_unload_size_800BF274 = 0;
        dword_800BF27C = 2;
        wave_load_ptr_800C0508 = cdload_buf_800BF010;
        dword_800C0650 = temp;
        return;
    }
    dword_800BF27C = 0;
    SD_8008395C(wave_data_800BF294, 2);
    printf("Complete Load Se:%x\n", wave_load_code_800C0528);
    wave_data_800BF294 = 0;
    nullsub_7_80081A10(&dword_800C0500, 0, wave_load_code_800C0528);
}

void WaveSpuTrans_80083944(void)
{
    /* do nothing */
}

int SD_SongLoadData_8008394C(int a1, int a2)
{
    return -1;
}

int SD_80083954(int a1, unsigned char *a2, int a3)
{
    return -1;
}

int SD_8008395C(int a1, int a2)
{
    return -1;
}

void StrFadeWkSet_80083964(void)
{
    unsigned int amount; // $a0

    if (dword_800C04EC == 0xFF0000F8)
    {
        amount = 100;
    }
    else
    {
        amount = 400;
        if (dword_800C04EC != 0xFF0000F9)
        {
            return;
        }
    }
    StrFadeIn_800822C8(amount);
    dword_800C04EC = 0;
    gStr_fadeout_2_800C0584 = gStreamVol_800BF15C;
}

int StrFadeInt_800839C8(void)
{
    SpuVoiceAttr attr;
    unsigned int diff;

    if (gStr_FadeOut1_800BF16C < 5)
    {
        return 0;
    }

    if (dword_800C04F4 != 0)
    {
        gStr_fadeout_2_800C0584 += dword_800C04F4;

        if (gStr_fadeout_2_800C0584 >= gStreamVol_800BF15C)
        {
            if (gStream_800C04F0 == -1)
            {
                keyOff_80081FC4(0x600000);
                gStr_FadeOut1_800BF16C = 7;
            }
            else
            {
                dword_800BF26C = 1;
            }

            dword_800C04F4 = 0;
            gStr_fadeout_2_800C0584 = gStreamVol_800BF15C;
        }
        else
        {
            dword_800BF26C = 0;
        }
    }

    attr.mask = SPU_VOICE_VOLL | SPU_VOICE_VOLR;
    attr.voice = SPU_21CH;

    diff = gStreamVol_800BF15C - gStr_fadeout_2_800C0584;

    if ((dword_800BF1DC != 0) && (dword_800C0418 < 2))
    {
        attr.volume.left = 0;
        attr.volume.right = 0;
    }
    else if (sound_mono_fg_800C050C != 0)
    {
        attr.volume.left = (diff * 0xA6) >> 8;
        attr.volume.right = (diff * 0xA6) >> 8;
    }
    else
    {
        attr.volume.left = 0;
        attr.volume.right = diff;
    }

    SpuSetVoiceAttr(&attr);

    attr.mask = SPU_VOICE_VOLL | SPU_VOICE_VOLR;
    attr.voice = SPU_22CH;

    if ((dword_800BF1DC != 0) && (dword_800C0418 < 2))
    {
        attr.volume.left = 0;
        attr.volume.right = 0;
    }
    else if (sound_mono_fg_800C050C != 0)
    {
        attr.volume.left = (diff * 0xA6) >> 8;
        attr.volume.right = (diff * 0xA6) >> 8;
    }
    else
    {
        attr.volume.left = diff;
        attr.volume.right = 0;
    }

    SpuSetVoiceAttr(&attr);
    return 0;
}

char num2char_80083E68(unsigned int num);

void code2name_80083BB4(unsigned int code, char *name)
{
    if ((code + 0xff000000) <= 0xffff)
    {
        name[ 0] = 'S';
        name[ 1] = 'G';
        name[ 2] = num2char_80083E68((code >> 20) & 0x0f);
        name[ 3] = num2char_80083E68((code >> 16) & 0x0f);
        name[ 4] = num2char_80083E68((code >> 12) & 0x0f);
        name[ 5] = num2char_80083E68((code >>  8) & 0x0f);
        name[ 6] = num2char_80083E68((code >>  4) & 0x0f);
        name[ 7] = num2char_80083E68(code & 0x0f);
        name[ 8] = '.';
        name[ 9] = 'M';
        name[10] = 'D';
        name[11] = 'X';
        name[12] = '\0';
        return;
    }
    if ((code + 0xfe000000) <= 0xffff)
    {
        name[ 0] = 'S';
        name[ 1] = 'E';
        name[ 2] = num2char_80083E68((code >> 20) & 0x0f);
        name[ 3] = num2char_80083E68((code >> 16) & 0x0f);
        name[ 4] = num2char_80083E68((code >> 12) & 0x0f);
        name[ 5] = num2char_80083E68((code >>  8) & 0x0f);
        name[ 6] = num2char_80083E68((code >>  4) & 0x0f);
        name[ 7] = num2char_80083E68(code & 0x0f);
        name[ 8] = '.';
        name[ 9] = 'E';
        name[10] = 'F';
        name[11] = 'X';
        name[12] = '\0';
        return;
    }
    if ((code + 0x20000000) <= 0xffff)
    {
        name[ 0] = 'S';
        name[ 1] = 'D';
        name[ 2] = num2char_80083E68((code >> 20) & 0x0f);
        name[ 3] = num2char_80083E68((code >> 16) & 0x0f);
        name[ 4] = num2char_80083E68((code >> 12) & 0x0f);
        name[ 5] = num2char_80083E68((code >>  8) & 0x0f);
        name[ 6] = num2char_80083E68((code >>  4) & 0x0f);
        name[ 7] = num2char_80083E68(code & 0x0f);
        name[ 8] = '.';
        name[ 9] = 'P';
        name[10] = 'C';
        name[11] = 'M';
        name[12] = '\0';
        //return;
    }
    if ((code + 0x02000000) <= 0xffff)
    {
        name[ 0] = 'W';
        name[ 1] = 'V';
        name[ 2] = num2char_80083E68((code >> 20) & 0x0f);
        name[ 3] = num2char_80083E68((code >> 16) & 0x0f);
        name[ 4] = num2char_80083E68((code >> 12) & 0x0f);
        name[ 5] = num2char_80083E68((code >>  8) & 0x0f);
        name[ 6] = num2char_80083E68((code >>  4) & 0x0f);
        name[ 7] = num2char_80083E68(code & 0x0f);
        name[ 8] = '.';
        name[ 9] = 'W';
        name[10] = 'V';
        name[11] = 'X';
        name[12] = '\0';
        return;
    }
}

char num2char_80083E68(unsigned int num)
{
    num &= 0x0f;
    if (num < 10)
    {
        num += '0';
    }
    else
    {
        num += ('a' - 10);
    }
    return num;
}

unsigned char *SD_SngDataLoadInit_80083E8C(unsigned short unused)
{
    sng_status_800C04F8 = 0;
    sng_status_800BF158 = 0;
    sng_off_80087E2C();
    printf("SD_SngDataLoadInit\n");
    return sd_sng_data_800C0420;
}

void SD_80083ED4(void)
{
    sng_status_800BF158 = 2;
}

unsigned char *SD_80083EE8(unsigned short unused)
{
    return se_exp_table_800C0520;
}

void SD_80083EF8(void)
{
    se_load_code_800BF28C = 0;
}

char *LoadInit_80083F08(unsigned short unused)
{
    char *ret;

    if (dword_800BF27C != 0)
    {
        printf("LoadInit %d\n", dword_800BF27C);
        *(int *)1 = 0;
    }
    ret = cdload_buf_800BF010;
    dword_800BF27C = 1;
    return ret;
}

int SD_80083F54(char *end)
{
    char        *src;
    char        *dst;
    int          offset;
    int          size;
    unsigned int used;

    byte_800C056C = 0x4F;

    src = cdload_buf_800BF010 + 16;

    offset = cdload_buf_800BF010[0] << 24;
    offset |= cdload_buf_800BF010[1] << 16;
    offset |= cdload_buf_800BF010[2] << 8;
    offset |= cdload_buf_800BF010[3];

    dst = (char *)voice_tbl_800BF1E0 + offset;

    size = cdload_buf_800BF010[4] << 24;
    size |= cdload_buf_800BF010[5] << 16;
    size |= cdload_buf_800BF010[6] << 8;
    size |= cdload_buf_800BF010[7];

    wave_load_ptr_800C0508 = cdload_buf_800BF010 + 16;

    if ((src + size) >= end)
    {
        return 0;
    }

    memcpy(dst, src, size);

    wave_load_ptr_800C0508 += size;

    spu_load_offset_800BF140 = wave_load_ptr_800C0508[0] << 24;
    spu_load_offset_800BF140 |= wave_load_ptr_800C0508[1] << 16;
    spu_load_offset_800BF140 |= wave_load_ptr_800C0508[2] << 8;
    spu_load_offset_800BF140 |= wave_load_ptr_800C0508[3];

    wave_unload_size_800BF274 = wave_load_ptr_800C0508[4] << 24;
    wave_unload_size_800BF274 |= wave_load_ptr_800C0508[5] << 16;
    wave_unload_size_800BF274 |= wave_load_ptr_800C0508[6] << 8;
    wave_unload_size_800BF274 |= wave_load_ptr_800C0508[7];

    wave_load_ptr_800C0508 += 16;

    used = (end - cdload_buf_800BF010) - (size + 32);
    if (used < wave_unload_size_800BF274)
    {
        dword_800C0650 = used;
    }
    else
    {
        dword_800C0650 = wave_unload_size_800BF274;
    }

    wave_unload_size_800BF274 -= dword_800C0650;
    wave_save_code_800C0578 = wave_load_code_800C0528;

    if (!SpuIsTransferCompleted(SPU_TRANSFER_PEEK))
    {
        printf("$");
    }

    SpuSetTransferStartAddr(spu_wave_start_ptr_800C052C + spu_load_offset_800BF140);
    SpuWrite(wave_load_ptr_800C0508, dword_800C0650);

    spu_load_offset_800BF140 += dword_800C0650;
    wave_load_ptr_800C0508 += dword_800C0650;

    return 1;
}

char *SD_WavLoadBuf_800841D4(char *arg0)
{
    char *buf;

    if (dword_800BF27C != 1 && wave_unload_size_800BF274 == 0)
    {
        dword_800BF27C = 0;
        return arg0;
    }

    switch (dword_800BF27C)
    {
    case 1:
        if (SD_80083F54(arg0) != 0)
        {
            dword_800BF27C = 3;
        }
        break;

    case 2:
        break;

    case 3:
        buf = cdload_buf_800BF010 + 0x18000;
        if (wave_load_ptr_800C0508 == buf)
        {
            wave_load_ptr_800C0508 = cdload_buf_800BF010;
        }
        else if (buf < wave_load_ptr_800C0508)
        {
            printf("!!! SD WAV LOAD BUF OVER !!!\n");
            *(int *)1 = 0;
        }
        if (arg0 < wave_load_ptr_800C0508)
        {
            dword_800C0650 = 0x18000 + cdload_buf_800BF010 - (wave_load_ptr_800C0508);
        }
        else
        {
            dword_800C0650 = arg0 - wave_load_ptr_800C0508;
        }
        wave_unload_size_800BF274 -= dword_800C0650;
        SpuSetTransferStartAddr(spu_wave_start_ptr_800C052C + spu_load_offset_800BF140);
        SpuWrite(wave_load_ptr_800C0508, dword_800C0650);
        spu_load_offset_800BF140 += dword_800C0650;
        wave_load_ptr_800C0508 += dword_800C0650;
        break;
    }

    if (arg0 >= cdload_buf_800BF010 + 0x18000)
    {
        arg0 = cdload_buf_800BF010;
    }
    return arg0;
}

void SD_Unload_800843BC(void)
{
    if (wave_unload_size_800BF274)
    {
        if (wave_load_ptr_800C0508 == cdload_buf_800BF010 + 0x18000)
        {
            wave_load_ptr_800C0508 = cdload_buf_800BF010;
        }
        SpuSetTransferStartAddr(spu_wave_start_ptr_800C052C + spu_load_offset_800BF140);
        SpuWrite(wave_load_ptr_800C0508, wave_unload_size_800BF274);
        spu_load_offset_800BF140 += wave_unload_size_800BF274;
        wave_load_ptr_800C0508 += wave_unload_size_800BF274;
    }
    dword_800BF27C = 0;
    if (wave_unload_size_800BF274)
    {
        printf("unload %d\n", wave_unload_size_800BF274);
    }
}
