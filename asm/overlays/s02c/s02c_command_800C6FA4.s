	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_command_800C6FA4
s02c_command_800C6FA4:
	dw 0x84850000 ; 800C6FA4
	dw 0x84830002 ; 800C6FA8
	dw 0x84820004 ; 800C6FAC
	dw 0x04A10002 ; 800C6FB0
	dw 0x00000000 ; 800C6FB4
	dw 0x00052823 ; 800C6FB8
	dw 0x04610002 ; 800C6FBC
	dw 0x00000000 ; 800C6FC0
	dw 0x00031823 ; 800C6FC4
	dw 0x00A32821 ; 800C6FC8
	dw 0x04410002 ; 800C6FCC
	dw 0x00000000 ; 800C6FD0
	dw 0x00021023 ; 800C6FD4
	dw 0x03E00008 ; 800C6FD8
	dw 0x00A21021 ; 800C6FDC