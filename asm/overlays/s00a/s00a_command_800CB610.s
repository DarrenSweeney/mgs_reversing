	opt	c+, at+, e+, n-
	section overlay.text

	xdef s00a_command_800CB610
s00a_command_800CB610:
	dw 0x24020002 ; 800CB610
	dw 0xA4820B22 ; 800CB614
	dw 0x24020005 ; 800CB618
	dw 0xA4820B24 ; 800CB61C
	dw 0x03E00008 ; 800CB620
	dw 0xAC800B28 ; 800CB624