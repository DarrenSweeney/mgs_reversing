	opt	c+, at+, e+, n-
	section overlay.text

	xdef d01a_blur_800CCCC8
d01a_blur_800CCCC8:
	dw 0x27BDFF60 ; 800CCCC8
	dw 0xAFB40088 ; 800CCCCC
	dw 0x0080A021 ; 800CCCD0
	dw 0xAFB20080 ; 800CCCD4
	dw 0x00A09021 ; 800CCCD8
	dw 0xAFBE0098 ; 800CCCDC
	dw 0x0280F021 ; 800CCCE0
	dw 0xAFB1007C ; 800CCCE4
	dw 0x02808821 ; 800CCCE8
	dw 0x26940028 ; 800CCCEC
	dw 0xAFB30084 ; 800CCCF0
	dw 0x02809821 ; 800CCCF4
	dw 0x26940028 ; 800CCCF8
	dw 0xAFB70094 ; 800CCCFC
	dw 0x0000B821 ; 800CCD00
	dw 0xAFB00078 ; 800CCD04
	dw 0x02E08021 ; 800CCD08
	dw 0xAFB5008C ; 800CCD0C
	dw 0x0280A821 ; 800CCD10
	dw 0x8FB400B4 ; 800CCD14
	dw 0x24040002 ; 800CCD18
	dw 0xAFB60090 ; 800CCD1C
	dw 0x26B60028 ; 800CCD20
	dw 0xAFBF009C ; 800CCD24
	dw 0x0C005C2F ; 800CCD28
	dw 0xAFA700AC ; 800CCD2C
	dw 0x24040002 ; 800CCD30
	dw 0x0C005C2F ; 800CCD34
	dw 0xAFA20028 ; 800CCD38
	dw 0x24040002 ; 800CCD3C
	dw 0x0C005C2F ; 800CCD40
	dw 0xAFA2002C ; 800CCD44
	dw 0x24040002 ; 800CCD48
	dw 0x0C005C2F ; 800CCD4C
	dw 0xAFA20030 ; 800CCD50
	dw 0x24040002 ; 800CCD54
	dw 0x0C005C2F ; 800CCD58
	dw 0xAFA20050 ; 800CCD5C
	dw 0x24040002 ; 800CCD60
	dw 0x0C005C2F ; 800CCD64
	dw 0xAFA20054 ; 800CCD68
	dw 0xAFA20058 ; 800CCD6C
	dw 0x24020002 ; 800CCD70
	dw 0x1282003E ; 800CCD74
	dw 0x2A820003 ; 800CCD78
	dw 0x10400005 ; 800CCD7C
	dw 0x24020001 ; 800CCD80
	dw 0x12820008 ; 800CCD84
	dw 0x00000000 ; 800CCD88
	dw 0x080333A2 ; 800CCD8C
	dw 0x00000000 ; 800CCD90
	dw 0x24020003 ; 800CCD94
	dw 0x12820037 ; 800CCD98
	dw 0x00000000 ; 800CCD9C
	dw 0x080333A2 ; 800CCDA0
	dw 0x00000000 ; 800CCDA4
	dw 0x8E420058 ; 800CCDA8
	dw 0x00000000 ; 800CCDAC
	dw 0x1040002A ; 800CCDB0
	dw 0x00000000 ; 800CCDB4
	dw 0x8E42005C ; 800CCDB8
	dw 0x00000000 ; 800CCDBC
	dw 0x00022080 ; 800CCDC0
	dw 0x00822021 ; 800CCDC4
	dw 0x000420C0 ; 800CCDC8
	dw 0x0C024942 ; 800CCDCC
	dw 0x00822021 ; 800CCDD0
	dw 0x8E43005C ; 800CCDD4
	dw 0x00408021 ; 800CCDD8
	dw 0x00032100 ; 800CCDDC
	dw 0x00832023 ; 800CCDE0
	dw 0x0C024942 ; 800CCDE4
	dw 0x00042040 ; 800CCDE8
	dw 0x02021021 ; 800CCDEC
	dw 0x04410002 ; 800CCDF0
	dw 0x00000000 ; 800CCDF4
	dw 0x244207FF ; 800CCDF8
	dw 0x8E43005C ; 800CCDFC
	dw 0x000212C3 ; 800CCE00
	dw 0xAE420070 ; 800CCE04
	dw 0x00032040 ; 800CCE08
	dw 0x00832021 ; 800CCE0C
	dw 0x00042080 ; 800CCE10
	dw 0x00832021 ; 800CCE14
	dw 0x00042080 ; 800CCE18
	dw 0x0C024942 ; 800CCE1C
	dw 0x00832021 ; 800CCE20
	dw 0x8E43005C ; 800CCE24
	dw 0x00408021 ; 800CCE28
	dw 0x00032080 ; 800CCE2C
	dw 0x00832021 ; 800CCE30
	dw 0x00042100 ; 800CCE34
	dw 0x0C024942 ; 800CCE38
	dw 0x00832021 ; 800CCE3C
	dw 0x02021021 ; 800CCE40
	dw 0x04410002 ; 800CCE44
	dw 0x00000000 ; 800CCE48
	dw 0x244207FF ; 800CCE4C
	dw 0x000212C3 ; 800CCE50
	dw 0x08033399 ; 800CCE54
	dw 0xAE420074 ; 800CCE58
	dw 0xAE400070 ; 800CCE5C
	dw 0xAE400074 ; 800CCE60
	dw 0x0000B821 ; 800CCE64
	dw 0x080333A2 ; 800CCE68
	dw 0x02E08021 ; 800CCE6C
	dw 0x0803339F ; 800CCE70
	dw 0x24170008 ; 800CCE74
	dw 0x2417FFF8 ; 800CCE78
	dw 0x02E08021 ; 800CCE7C
	dw 0xAE400070 ; 800CCE80
	dw 0xAE400074 ; 800CCE84
	dw 0x96420064 ; 800CCE88
	dw 0x00000000 ; 800CCE8C
	dw 0x00571021 ; 800CCE90
	dw 0xA6220008 ; 800CCE94
	dw 0x96420068 ; 800CCE98
	dw 0x00000000 ; 800CCE9C
	dw 0x00501021 ; 800CCEA0
	dw 0xA622000A ; 800CCEA4
	dw 0x96420070 ; 800CCEA8
	dw 0x97A30028 ; 800CCEAC
	dw 0x244200A0 ; 800CCEB0
	dw 0x00621821 ; 800CCEB4
	dw 0xA6230010 ; 800CCEB8
	dw 0x96420068 ; 800CCEBC
	dw 0x00000000 ; 800CCEC0
	dw 0x00501021 ; 800CCEC4
	dw 0xA6220012 ; 800CCEC8
	dw 0x96420064 ; 800CCECC
	dw 0x96240010 ; 800CCED0
	dw 0x00571021 ; 800CCED4
	dw 0xA6220018 ; 800CCED8
	dw 0x96420074 ; 800CCEDC
	dw 0x97A30050 ; 800CCEE0
	dw 0x24420070 ; 800CCEE4
	dw 0x00621821 ; 800CCEE8
	dw 0xA623001A ; 800CCEEC
	dw 0x96420070 ; 800CCEF0
	dw 0x97A3002C ; 800CCEF4
	dw 0x244200A0 ; 800CCEF8
	dw 0x00621821 ; 800CCEFC
	dw 0xA6230020 ; 800CCF00
	dw 0x96430074 ; 800CCF04
	dw 0x97A20054 ; 800CCF08
	dw 0x24630070 ; 800CCF0C
	dw 0x00431021 ; 800CCF10
	dw 0xA6220022 ; 800CCF14
	dw 0xA6640008 ; 800CCF18
	dw 0x96220012 ; 800CCF1C
	dw 0x00000000 ; 800CCF20
	dw 0xA662000A ; 800CCF24
	dw 0x96420064 ; 800CCF28
	dw 0x00172823 ; 800CCF2C
	dw 0x2442FEC0 ; 800CCF30
	dw 0x00A21023 ; 800CCF34
	dw 0xA6620010 ; 800CCF38
	dw 0x96420068 ; 800CCF3C
	dw 0x00000000 ; 800CCF40
	dw 0x00501021 ; 800CCF44
	dw 0xA6620012 ; 800CCF48
	dw 0x96220020 ; 800CCF4C
	dw 0x00000000 ; 800CCF50
	dw 0xA6620018 ; 800CCF54
	dw 0x96220022 ; 800CCF58
	dw 0x00000000 ; 800CCF5C
	dw 0xA662001A ; 800CCF60
	dw 0x96420064 ; 800CCF64
	dw 0x00000000 ; 800CCF68
	dw 0x2442FEC0 ; 800CCF6C
	dw 0x00A21023 ; 800CCF70
	dw 0xA6620020 ; 800CCF74
	dw 0x96420074 ; 800CCF78
	dw 0x97A30058 ; 800CCF7C
	dw 0x24420070 ; 800CCF80
	dw 0x00621821 ; 800CCF84
	dw 0xA6630022 ; 800CCF88
	dw 0x96220018 ; 800CCF8C
	dw 0x00000000 ; 800CCF90
	dw 0xA6A20008 ; 800CCF94
	dw 0x9622001A ; 800CCF98
	dw 0x00000000 ; 800CCF9C
	dw 0xA6A2000A ; 800CCFA0
	dw 0x96220020 ; 800CCFA4
	dw 0x00000000 ; 800CCFA8
	dw 0xA6A20010 ; 800CCFAC
	dw 0x96220022 ; 800CCFB0
	dw 0x00000000 ; 800CCFB4
	dw 0xA6A20012 ; 800CCFB8
	dw 0x96420064 ; 800CCFBC
	dw 0x00000000 ; 800CCFC0
	dw 0x00571021 ; 800CCFC4
	dw 0xA6A20018 ; 800CCFC8
	dw 0x9642006C ; 800CCFCC
	dw 0x00102023 ; 800CCFD0
	dw 0x2442FF20 ; 800CCFD4
	dw 0x00821023 ; 800CCFD8
	dw 0xA6A2001A ; 800CCFDC
	dw 0x96420070 ; 800CCFE0
	dw 0x97A30030 ; 800CCFE4
	dw 0x244200A0 ; 800CCFE8
	dw 0x00621821 ; 800CCFEC
	dw 0xA6A30020 ; 800CCFF0
	dw 0x9642006C ; 800CCFF4
	dw 0x00000000 ; 800CCFF8
	dw 0x2442FF20 ; 800CCFFC
	dw 0x00821023 ; 800CD000
	dw 0xA6A20022 ; 800CD004
	dw 0x96220020 ; 800CD008
	dw 0x00000000 ; 800CD00C
	dw 0xA6C20008 ; 800CD010
	dw 0x96220022 ; 800CD014
	dw 0x00000000 ; 800CD018
	dw 0xA6C2000A ; 800CD01C
	dw 0x96620020 ; 800CD020
	dw 0x00000000 ; 800CD024
	dw 0xA6C20010 ; 800CD028
	dw 0x96620022 ; 800CD02C
	dw 0x00000000 ; 800CD030
	dw 0xA6C20012 ; 800CD034
	dw 0x96A20020 ; 800CD038
	dw 0x00000000 ; 800CD03C
	dw 0xA6C20018 ; 800CD040
	dw 0x96A20022 ; 800CD044
	dw 0x2406009F ; 800CD048
	dw 0xA6C2001A ; 800CD04C
	dw 0x96420064 ; 800CD050
	dw 0x00000000 ; 800CD054
	dw 0x2442FEC0 ; 800CD058
	dw 0x00A22823 ; 800CD05C
	dw 0xA6C50020 ; 800CD060
	dw 0x9642006C ; 800CD064
	dw 0x00000000 ; 800CD068
	dw 0x2442FF20 ; 800CD06C
	dw 0x00822023 ; 800CD070
	dw 0xA6C40022 ; 800CD074
	dw 0x92420064 ; 800CD078
	dw 0x2404006F ; 800CD07C
	dw 0x24420002 ; 800CD080
	dw 0xA222001C ; 800CD084
	dw 0xA222000C ; 800CD088
	dw 0x92420068 ; 800CD08C
	dw 0x00000000 ; 800CD090
	dw 0x24420002 ; 800CD094
	dw 0xA2220015 ; 800CD098
	dw 0xA222000D ; 800CD09C
	dw 0x8E420070 ; 800CD0A0
	dw 0x8E430074 ; 800CD0A4
	dw 0x00C21023 ; 800CD0A8
	dw 0x00831823 ; 800CD0AC
	dw 0xA2220024 ; 800CD0B0
	dw 0xA2220014 ; 800CD0B4
	dw 0xA2230025 ; 800CD0B8
	dw 0xA223001D ; 800CD0BC
	dw 0x92420070 ; 800CD0C0
	dw 0x24050020 ; 800CD0C4
	dw 0x00A21023 ; 800CD0C8
	dw 0xA262001C ; 800CD0CC
	dw 0xA262000C ; 800CD0D0
	dw 0x92420068 ; 800CD0D4
	dw 0x240700BD ; 800CD0D8
	dw 0x24420002 ; 800CD0DC
	dw 0xA2620015 ; 800CD0E0
	dw 0xA262000D ; 800CD0E4
	dw 0x8E420064 ; 800CD0E8
	dw 0x8E430074 ; 800CD0EC
	dw 0x00E21023 ; 800CD0F0
	dw 0x00832023 ; 800CD0F4
	dw 0xA2620024 ; 800CD0F8
	dw 0xA2620014 ; 800CD0FC
	dw 0xA2640025 ; 800CD100
	dw 0xA264001D ; 800CD104
	dw 0x92420064 ; 800CD108
	dw 0x03C0A021 ; 800CD10C
	dw 0x24420002 ; 800CD110
	dw 0xA2A2001C ; 800CD114
	dw 0xA2A2000C ; 800CD118
	dw 0x92420074 ; 800CD11C
	dw 0x24040070 ; 800CD120
	dw 0x00821023 ; 800CD124
	dw 0xA2A20015 ; 800CD128
	dw 0xA2A2000D ; 800CD12C
	dw 0x8E430070 ; 800CD130
	dw 0x8E42006C ; 800CD134
	dw 0x00C33023 ; 800CD138
	dw 0x240300DD ; 800CD13C
	dw 0x00621023 ; 800CD140
	dw 0xA2A60024 ; 800CD144
	dw 0xA2A60014 ; 800CD148
	dw 0xA2A20025 ; 800CD14C
	dw 0xA2A2001D ; 800CD150
	dw 0x92420070 ; 800CD154
	dw 0x0000F021 ; 800CD158
	dw 0x00A22823 ; 800CD15C
	dw 0xA2C5001C ; 800CD160
	dw 0xA2C5000C ; 800CD164
	dw 0x8FA800AC ; 800CD168
	dw 0x24020001 ; 800CD16C
	dw 0x0048B823 ; 800CD170
	dw 0x92420074 ; 800CD174
	dw 0x00174080 ; 800CD178
	dw 0xAFA80070 ; 800CD17C
	dw 0x00822023 ; 800CD180
	dw 0xA2C40015 ; 800CD184
	dw 0xA2C4000D ; 800CD188
	dw 0x8E420064 ; 800CD18C
	dw 0x8E44006C ; 800CD190
	dw 0x00E23823 ; 800CD194
	dw 0x00641823 ; 800CD198
	dw 0xA2C70024 ; 800CD19C
	dw 0xA2C70014 ; 800CD1A0
	dw 0xA2C30025 ; 800CD1A4
	dw 0xA2C3001D ; 800CD1A8
	dw 0x00009821 ; 800CD1AC
	dw 0x02609021 ; 800CD1B0
	dw 0x00008821 ; 800CD1B4
	dw 0x2408FFC0 ; 800CD1B8
	dw 0x0248B024 ; 800CD1BC
	dw 0x8FA80070 ; 800CD1C0
	dw 0x26900006 ; 800CD1C4
	dw 0x01171021 ; 800CD1C8
	dw 0x0002A980 ; 800CD1CC
	dw 0x24040002 ; 800CD1D0
	dw 0x24020009 ; 800CD1D4
	dw 0xA202FFFD ; 800CD1D8
	dw 0x2402002C ; 800CD1DC
	dw 0x02B63021 ; 800CD1E0
	dw 0xA2020001 ; 800CD1E4
	dw 0x8FA500B0 ; 800CD1E8
	dw 0x0C024906 ; 800CD1EC
	dw 0x00003821 ; 800CD1F0
	dw 0x26940028 ; 800CD1F4
	dw 0x92030001 ; 800CD1F8
	dw 0x26310001 ; 800CD1FC
	dw 0xA6020010 ; 800CD200
	dw 0x24020080 ; 800CD204
	dw 0xA202FFFE ; 800CD208
	dw 0xA202FFFF ; 800CD20C
	dw 0xA2020000 ; 800CD210
	dw 0x34630002 ; 800CD214
	dw 0xA2030001 ; 800CD218
	dw 0x1A20FFEC ; 800CD21C
	dw 0x26100028 ; 800CD220
	dw 0x26730001 ; 800CD224
	dw 0x2A620002 ; 800CD228
	dw 0x1440FFE1 ; 800CD22C
	dw 0x265200A0 ; 800CD230
	dw 0x27DE0001 ; 800CD234
	dw 0x2BC20002 ; 800CD238
	dw 0x1440FFDC ; 800CD23C
	dw 0x00009821 ; 800CD240
	dw 0x8FBF009C ; 800CD244
	dw 0x8FBE0098 ; 800CD248
	dw 0x8FB70094 ; 800CD24C
	dw 0x8FB60090 ; 800CD250
	dw 0x8FB5008C ; 800CD254
	dw 0x8FB40088 ; 800CD258
	dw 0x8FB30084 ; 800CD25C
	dw 0x8FB20080 ; 800CD260
	dw 0x8FB1007C ; 800CD264
	dw 0x8FB00078 ; 800CD268
	dw 0x03E00008 ; 800CD26C
	dw 0x27BD00A0 ; 800CD270
