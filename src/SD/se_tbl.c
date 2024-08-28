#include "SD/sound.h"
#include "SD/sd_incl.h"

/* data definition */
#include "se_data/blob.h"

unsigned char se_dummy[] = { 0x00,0x00,0xfe,0xff };

#define ADDR(_array)    ((unsigned int)&_array[0])
#define SE_DUMMY        ((unsigned int)&se_dummy[0])

SETBL se_tbl_800A22C4[128] = {
    /* pri,tracks,kind,character */
    { 0x01, 0x01, 0x01, 0x00, { SE_DUMMY, SE_DUMMY, SE_DUMMY }}, /* 0 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(shot_0100),  SE_DUMMY, SE_DUMMY }}, /* 1 */
    { 0x10, 0x01, 0x01, 0x00, { ADDR(stepl0100),  SE_DUMMY, SE_DUMMY }}, /* 2 */
    { 0x10, 0x01, 0x01, 0x00, { ADDR(stepr0100),  SE_DUMMY, SE_DUMMY }}, /* 3 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(karasht100), SE_DUMMY, SE_DUMMY }}, /* 4 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(hohuku0300), SE_DUMMY, SE_DUMMY }}, /* 5 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(hohuku0400), SE_DUMMY, SE_DUMMY }}, /* 6 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(senaka0100), SE_DUMMY, SE_DUMMY }}, /* 7 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(stand0100),  SE_DUMMY, SE_DUMMY }}, /* 8 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(kamae0100),  SE_DUMMY, SE_DUMMY }}, /* 9 */
    { 0x30, 0x01, 0x00, 0x00, { ADDR(heart0100),  SE_DUMMY, SE_DUMMY }}, /* 10 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(full000500), SE_DUMMY, SE_DUMMY }}, /* 11 */
    { 0xB0, 0x01, 0x00, 0x00, { ADDR(kaihuku100), SE_DUMMY, SE_DUMMY }}, /* 12 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(item000300), SE_DUMMY, SE_DUMMY }}, /* 13 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(radar00100), SE_DUMMY, SE_DUMMY }}, /* 14 */
    { 0xF0, 0x03, 0x00, 0x00, { ADDR(over0300), ADDR(over0301), ADDR(over0302) }}, /* 15 */
    { 0x20, 0x01, 0x00, 0x00, { ADDR(seunk01600), SE_DUMMY, SE_DUMMY }}, /* 16 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(seunk01700), SE_DUMMY, SE_DUMMY }}, /* 17 */
    { 0xA0, 0x01, 0x01, 0x01, { ADDR(pout000300), SE_DUMMY, SE_DUMMY }}, /* 18 */
    { 0xA0, 0x01, 0x01, 0x01, { ADDR(sneeze0100), SE_DUMMY, SE_DUMMY }}, /* 19 */
    { 0x90, 0x01, 0x01, 0x00, { ADDR(idec0300),   SE_DUMMY, SE_DUMMY }}, /* 20 */
    { 0x20, 0x01, 0x00, 0x00, { ADDR(idisp0200),  SE_DUMMY, SE_DUMMY }}, /* 21 */
    { 0x90, 0x02, 0x00, 0x00, { ADDR(iget0100), ADDR(iget0101), SE_DUMMY }}, /* 22 */
    { 0x10, 0x01, 0x00, 0x00, { ADDR(seunk02300), SE_DUMMY, SE_DUMMY }}, /* 23 */
    { 0xA0, 0x01, 0x01, 0x01, { ADDR(seunk02400), SE_DUMMY, SE_DUMMY }}, /* 24 */
    { 0xA0, 0x01, 0x01, 0x01, { ADDR(seunk02500), SE_DUMMY, SE_DUMMY }}, /* 25 */
    { 0xF0, 0x01, 0x00, 0x01, { ADDR(pout000100), SE_DUMMY, SE_DUMMY }}, /* 26 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(rifle0100),  SE_DUMMY, SE_DUMMY }}, /* 27 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(step0200),   SE_DUMMY, SE_DUMMY }}, /* 28 */
    { 0x10, 0x01, 0x01, 0x00, { ADDR(moustep200), SE_DUMMY, SE_DUMMY }}, /* 29 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(wstep0100),  SE_DUMMY, SE_DUMMY }}, /* 30 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(cur0100),    SE_DUMMY, SE_DUMMY }}, /* 31 */
    { 0x90, 0x02, 0x00, 0x00, { ADDR(win0100), ADDR(win0101), SE_DUMMY }}, /* 32 */
    { 0x90, 0x03, 0x00, 0x00, { ADDR(start0100), ADDR(start0101), ADDR(start0102) }}, /* 33 */
    { 0x90, 0x02, 0x00, 0x00, { ADDR(idec0200), ADDR(idec0201), SE_DUMMY }}, /* 34 */
    { 0x90, 0x01, 0x01, 0x00, { ADDR(buzzer0100), SE_DUMMY, SE_DUMMY }}, /* 35 */
    { 0x20, 0x02, 0x00, 0x00, { ADDR(zoom0100), ADDR(zoom0101), SE_DUMMY }}, /* 36 */
    { 0x60, 0x01, 0x01, 0x00, { ADDR(ataru0100),  SE_DUMMY, SE_DUMMY }}, /* 37 */
    { 0x60, 0x01, 0x01, 0x00, { ADDR(edmg0100),   SE_DUMMY, SE_DUMMY }}, /* 38 */
    { 0x10, 0x01, 0x01, 0x00, { ADDR(reb0100),    SE_DUMMY, SE_DUMMY }}, /* 39 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(rebdrm0100), SE_DUMMY, SE_DUMMY }}, /* 40 */
    { 0x90, 0x01, 0x01, 0x00, { ADDR(exp_0500),   SE_DUMMY, SE_DUMMY }}, /* 41 */
    { 0xA0, 0x01, 0x00, 0x00, { ADDR(siren0600),  SE_DUMMY, SE_DUMMY }}, /* 42 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(bound0200),  SE_DUMMY, SE_DUMMY }}, /* 43 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(pin0100),    SE_DUMMY, SE_DUMMY }}, /* 44 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(shot_e0300), SE_DUMMY, SE_DUMMY }}, /* 45 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(shot_e0200), SE_DUMMY, SE_DUMMY }}, /* 46 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(reload0100), SE_DUMMY, SE_DUMMY }}, /* 47 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(seunk04800), SE_DUMMY, SE_DUMMY }}, /* 48 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(c4put0100),  SE_DUMMY, SE_DUMMY }}, /* 49 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(c4sw0100),   SE_DUMMY, SE_DUMMY }}, /* 50 */
    { 0x70, 0x01, 0x01, 0x00, { ADDR(down000200), SE_DUMMY, SE_DUMMY }}, /* 51 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(punchit100), SE_DUMMY, SE_DUMMY }}, /* 52 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(kickhit100), SE_DUMMY, SE_DUMMY }}, /* 53 */
    { 0x10, 0x01, 0x00, 0x00, { ADDR(isel000300), SE_DUMMY, SE_DUMMY }}, /* 54 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(wall0200),   SE_DUMMY, SE_DUMMY }}, /* 55 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(p_swing100), SE_DUMMY, SE_DUMMY }}, /* 56 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(k_swing100), SE_DUMMY, SE_DUMMY }}, /* 57 */
    { 0x90, 0x02, 0x00, 0x00, { ADDR(chaf000300), ADDR(chaf000301), SE_DUMMY }}, /* 58 */
    { 0x60, 0x01, 0x01, 0x00, { ADDR(hibana0100), SE_DUMMY, SE_DUMMY }}, /* 59 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(seunk06000), SE_DUMMY, SE_DUMMY }}, /* 60 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(seunk06100), SE_DUMMY, SE_DUMMY }}, /* 61 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(rebglass00), SE_DUMMY, SE_DUMMY }}, /* 62 */
    { 0x60, 0x01, 0x01, 0x00, { ADDR(glass1100),  SE_DUMMY, SE_DUMMY }}, /* 63 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(seunk06400), SE_DUMMY, SE_DUMMY }}, /* 64 */
    { 0x90, 0x02, 0x01, 0x00, { ADDR(bakuha0100), ADDR(bakuha0101), SE_DUMMY }}, /* 65 */
    { 0x70, 0x01, 0x01, 0x00, { ADDR(chaf000200), SE_DUMMY, SE_DUMMY }}, /* 66 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(backcls100), SE_DUMMY, SE_DUMMY }}, /* 67 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(backcls200), SE_DUMMY, SE_DUMMY }}, /* 68 */
    { 0x01, 0x00, 0x00, 0x00, { SE_DUMMY, SE_DUMMY, SE_DUMMY }}, /* 69 */
    { 0x01, 0x00, 0x00, 0x00, { SE_DUMMY, SE_DUMMY, SE_DUMMY }}, /* 70 */
    { 0x01, 0x00, 0x00, 0x00, { SE_DUMMY, SE_DUMMY, SE_DUMMY }}, /* 71 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(seunk07200), SE_DUMMY, SE_DUMMY }}, /* 72 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(shot_m0200), SE_DUMMY, SE_DUMMY }}, /* 73 */
    { 0x80, 0x02, 0x00, 0x00, { ADDR(facechg100), ADDR(facechg101), SE_DUMMY }}, /* 74 */
    { 0xFF, 0x01, 0x00, 0x00, { ADDR(run0000100), SE_DUMMY, SE_DUMMY }}, /* 75 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(seunk07600), SE_DUMMY, SE_DUMMY }}, /* 76 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(seunk07700), SE_DUMMY, SE_DUMMY }}, /* 77 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(ninja0100),  SE_DUMMY, SE_DUMMY }}, /* 78 */
    { 0x30, 0x01, 0x00, 0x00, { ADDR(seunk07900), SE_DUMMY, SE_DUMMY }}, /* 79 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(ninja0200),  SE_DUMMY, SE_DUMMY }}, /* 80 */
    { 0x60, 0x01, 0x01, 0x00, { ADDR(hiza0100),   SE_DUMMY, SE_DUMMY }}, /* 81 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(seunk08200), SE_DUMMY, SE_DUMMY }}, /* 82 */
    { 0xA0, 0x03, 0x00, 0x00, { ADDR(seunk08300), ADDR(seunk08301), ADDR(seunk08302) }}, /* 83 */
    { 0x80, 0x02, 0x00, 0x00, { ADDR(r_windw100), ADDR(r_windw101), SE_DUMMY }}, /* 84 */
    { 0x80, 0x01, 0x00, 0x00, { ADDR(r_sel0100),  SE_DUMMY, SE_DUMMY }}, /* 85 */
    { 0x80, 0x01, 0x00, 0x00, { ADDR(r_snd0100),  SE_DUMMY, SE_DUMMY }}, /* 86 */
    { 0x80, 0x02, 0x00, 0x00, { ADDR(r_windw200), ADDR(r_windw201), SE_DUMMY }}, /* 87 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(dclose0300), SE_DUMMY, SE_DUMMY }}, /* 88 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(dclose0400), SE_DUMMY, SE_DUMMY }}, /* 89 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(dclose0500), SE_DUMMY, SE_DUMMY }}, /* 90 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(dopen0300),  SE_DUMMY, SE_DUMMY }}, /* 91 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(dopen0400),  SE_DUMMY, SE_DUMMY }}, /* 92 */
    { 0x30, 0x01, 0x01, 0x00, { ADDR(dopen0500),  SE_DUMMY, SE_DUMMY }}, /* 93 */
    { 0x10, 0x01, 0x01, 0x00, { ADDR(camera0700), SE_DUMMY, SE_DUMMY }}, /* 94 */
    { 0x90, 0x01, 0x01, 0x00, { ADDR(camera0300), SE_DUMMY, SE_DUMMY }}, /* 95 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(button0100), SE_DUMMY, SE_DUMMY }}, /* 96 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(elecls0300), SE_DUMMY, SE_DUMMY }}, /* 97 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(eleopn0300), SE_DUMMY, SE_DUMMY }}, /* 98 */
    { 0x10, 0x01, 0x01, 0x00, { ADDR(sight0800),  SE_DUMMY, SE_DUMMY }}, /* 99 */
    { 0xFF, 0x03, 0x00, 0x00, { ADDR(inelev0200), ADDR(inelev0201), ADDR(inelev0202) }}, /* 100 */
    { 0x40, 0x01, 0x01, 0x00, { ADDR(seunk10100), SE_DUMMY, SE_DUMMY }}, /* 101 */
    { 0xF0, 0x02, 0x00, 0x00, { ADDR(start00100), ADDR(start00101), SE_DUMMY }}, /* 102 */
    { 0x20, 0x01, 0x00, 0x00, { ADDR(r_tune0100), SE_DUMMY, SE_DUMMY }}, /* 103 */
    { 0x80, 0x01, 0x00, 0x00, { ADDR(r_cancel00), SE_DUMMY, SE_DUMMY }}, /* 104 */
    { 0x80, 0x01, 0x00, 0x00, { ADDR(r_cursor00), SE_DUMMY, SE_DUMMY }}, /* 105 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(o2damage00), SE_DUMMY, SE_DUMMY }}, /* 106 */
    { 0x90, 0x01, 0x00, 0x01, { ADDR(pout000200), SE_DUMMY, SE_DUMMY }}, /* 107 */
    { 0x80, 0x02, 0x00, 0x00, { ADDR(r_noise100), ADDR(r_noise101), SE_DUMMY }}, /* 108 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(camera0600), SE_DUMMY, SE_DUMMY }}, /* 109 */
    { 0x40, 0x02, 0x01, 0x00, { ADDR(shattr0400), ADDR(shattr0401), SE_DUMMY }}, /* 110 */
    { 0x30, 0x02, 0x01, 0x00, { ADDR(shattr0600), ADDR(shattr0601), SE_DUMMY }}, /* 111 */
    { 0x20, 0x01, 0x01, 0x00, { ADDR(el_chm0200), SE_DUMMY, SE_DUMMY }}, /* 112 */
    { 0x30, 0x02, 0x01, 0x00, { ADDR(elstop0600), ADDR(elstop0601), SE_DUMMY }}, /* 113 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(mask000200), SE_DUMMY, SE_DUMMY }}, /* 114 */
    { 0xB0, 0x01, 0x00, 0x00, { ADDR(ration0100), SE_DUMMY, SE_DUMMY }}, /* 115 */
    { 0x40, 0x01, 0x00, 0x00, { ADDR(signal0200), SE_DUMMY, SE_DUMMY }}, /* 116 */
    { 0xB0, 0x01, 0x00, 0x00, { ADDR(clock00100), SE_DUMMY, SE_DUMMY }}, /* 117 */
    { 0x80, 0x01, 0x00, 0x00, { ADDR(mmask00100), SE_DUMMY, SE_DUMMY }}, /* 118 */
    { 0xB0, 0x01, 0x00, 0x00, { ADDR(signal0400), SE_DUMMY, SE_DUMMY }}, /* 119 */
    { 0x90, 0x02, 0x00, 0x00, { ADDR(radar00300), ADDR(radar00301), SE_DUMMY }}, /* 120 */
    { 0xF0, 0x02, 0x00, 0x00, { ADDR(jingle0100), ADDR(jingle0101), SE_DUMMY }}, /* 121 */
    { 0xF0, 0x03, 0x00, 0x00, { ADDR(jingle0200), ADDR(jingle0201), ADDR(jingle0202) }}, /* 122 */
    { 0xF0, 0x03, 0x00, 0x00, { ADDR(chr_dsp100), ADDR(chr_dsp101), ADDR(chr_dsp102) }}, /* 123 */
    { 0x40, 0x02, 0x01, 0x00, { ADDR(shattr0b00), ADDR(shattr0b01), SE_DUMMY }}, /* 124 */
    { 0xF0, 0x02, 0x00, 0x00, { ADDR(menuopn100), ADDR(menuopn101), SE_DUMMY }}, /* 125 */
    { 0xB0, 0x03, 0x00, 0x00, { ADDR(kaihuku400), ADDR(kaihuku401), ADDR(kaihuku402) }}, /* 126 */
    { 0x90, 0x01, 0x00, 0x00, { ADDR(idec0400),   SE_DUMMY, SE_DUMMY }}  /* 127 */
};
