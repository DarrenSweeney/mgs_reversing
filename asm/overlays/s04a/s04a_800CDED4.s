	opt	c+, at+, e+, n-
	section overlay.text

	xdef s04a_800CDED4
s04a_800CDED4:
	dw 0x27BDFFE0 ; 800CDED4
	dw 0x00801021 ; 800CDED8
	dw 0x00A02021 ; 800CDEDC
	dw 0x00402821 ; 800CDEE0
	dw 0xAFBF0018 ; 800CDEE4
	dw 0x0C005B50 ; 800CDEE8
	dw 0x27A60010 ; 800CDEEC
	dw 0x0C005BBE ; 800CDEF0
	dw 0x27A40010 ; 800CDEF4
	dw 0x8FBF0018 ; 800CDEF8
	dw 0x00000000 ; 800CDEFC
	dw 0x03E00008 ; 800CDF00
	dw 0x27BD0020 ; 800CDF04
