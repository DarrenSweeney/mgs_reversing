	opt	c+, at+, e+, n-
	section overlay.text

	xdef d01a_command_800C76DC
d01a_command_800C76DC:
	dw 0x3C02800D ; 800C76DC
	dw 0x24421230 ; 800C76E0
	dw 0x00042080 ; 800C76E4
	dw 0x00822021 ; 800C76E8
	dw 0x03E00008 ; 800C76EC
	dw 0xAC850148 ; 800C76F0
