	opt	c+, at+, e+, n-
	section .text

	xdef GM_Reset_helper4_80032C68
GM_Reset_helper4_80032C68:
	dw 0x3C02800C ; 0x80032C68
	dw 0x24428230 ; 0x80032C6C
	dw 0x24030008 ; 0x80032C70
	dw 0xAC40000C ; 0x80032C74
	dw 0x2463FFFF ; 0x80032C78
	dw 0x1C60FFFD ; 0x80032C7C
	dw 0x24420010 ; 0x80032C80
	dw 0x03E00008 ; 0x80032C84
	dw 0x00000000 ; 0x80032C88