	opt	c+, at+, e+, n-
	section overlay.text

	xdef s00a_elevator_800D8808
s00a_elevator_800D8808:
	dw 0x27BDFFE8 ; 800D8808
	dw 0x308400FF ; 800D880C
	dw 0xAFBF0010 ; 800D8810
	dw 0x0C0361F2 ; 800D8814
	dw 0x00002821 ; 800D8818
	dw 0x8FBF0010 ; 800D881C
	dw 0x00000000 ; 800D8820
	dw 0x03E00008 ; 800D8824
	dw 0x27BD0018 ; 800D8828