	opt	c+, at+, e+, n-
	section overlay.text

	xdef select_800C3C28
select_800C3C28:
	dw 0x28A2000F ; 800C3C28
	dw 0x1040000F ; 800C3C2C
	dw 0x27BDFFF8 ; 800C3C30
	dw 0x00051040 ; 800C3C34
	dw 0x00441021 ; 800C3C38
	dw 0x80430002 ; 800C3C3C
	dw 0x80460003 ; 800C3C40
	dw 0xA3A30000 ; 800C3C44
	dw 0xA3A60001 ; 800C3C48
	dw 0x80430000 ; 800C3C4C
	dw 0x80460001 ; 800C3C50
	dw 0xA0430002 ; 800C3C54
	dw 0xA0460003 ; 800C3C58
	dw 0x83A30000 ; 800C3C5C
	dw 0x83A60001 ; 800C3C60
	dw 0xA0430000 ; 800C3C64
	dw 0xA0460001 ; 800C3C68
	dw 0x03E00008 ; 800C3C6C
	dw 0x27BD0008 ; 800C3C70