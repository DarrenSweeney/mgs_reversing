	opt	c+, at+, e+, n-
	section overlay.text

	xdef s03e_fadeio_800CA840
s03e_fadeio_800CA840:
	dw 0x27BDFFE8 ; 800CA840
	dw 0x308400FF ; 800CA844
	dw 0xAFBF0010 ; 800CA848
	dw 0x0C0329FF ; 800CA84C
	dw 0x00002821 ; 800CA850
	dw 0x8FBF0010 ; 800CA854
	dw 0x3042FFFF ; 800CA858
	dw 0x03E00008 ; 800CA85C
	dw 0x27BD0018 ; 800CA860
