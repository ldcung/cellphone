
	AREA EXAMPLE,CODE,READONLY
	ENTRY
START
	;MOV R1,#1
	
	;----------------------------
	LDR R0,=0x7e004000;WATCON
  	LDR R1,=0x00
  	STR R1,[r0]
  	;----------------------------
  	LDR R0,=0x7f008820;GPMCON
  	LDR R1,=0x1111
  	STR R1,[r0]
LOOP
  	LDR R0,=0x7f008824;GPMDAT
  	LDR R1,=0xaa
  	STR R1,[r0]
  	BL  DELAY
  	LDR R0,=0x7f008824;GPMDAT
  	LDR R1,=0x55
  	STR R1,[r0]
  	BL  DELAY
	B LOOP
DELAY
	MOV R2,#0x00ffffff
DEL	SUB R2,R2,#1
	CMP R2,#0
	BNE DEL 
	MOV R15,R14;;×Ó³ÌÐò·µ»Ø
	END