	opt	c+, at+, e+, n-
	section overlay.text

	xdef s03e_fadeio_800CB0CC
s03e_fadeio_800CB0CC:
	dw 0x27BDFFE8 ; 800CB0CC
	dw 0xAFBF0010 ; 800CB0D0
	dw 0x8C840024 ; 800CB0D4
	dw 0x00000000 ; 800CB0D8
	dw 0x10800003 ; 800CB0DC
	dw 0x00000000 ; 800CB0E0
	dw 0x0C005895 ; 800CB0E4
	dw 0x00000000 ; 800CB0E8
	dw 0x8FBF0010 ; 800CB0EC
	dw 0x00000000 ; 800CB0F0
	dw 0x03E00008 ; 800CB0F4
	dw 0x27BD0018 ; 800CB0F8
