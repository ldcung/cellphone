	;IMPORT Main
	
	;AREA mycode,CODE,READONLY
	;global start
	;ENTRY
;start
	;b Main
	
;	END
;-----------------------------------------------------------------------------------------------------------------------
; INCLUDE s3c6410.inc
;----------------------------------------------------------------
 IMPORT main   ;C Entry Point for Steppingstone Loader
;----------------------------------------------------------------
 
 EXPORT ENTRY
 AREA Init,CODE,READONLY
;----------------------------------------------------------------
ENTRY
  b ResetHandler
  b .
  b .
  b .
  b .
  b .
  b .
  b .
   
   
 
  
ResetHandler
;----------------------------------------
; Disable WatchDog Timer
;----------------------------------------  
  ldr r0,=0x7e004000
  ldr r1,=0x00
  str r1,[r0]
  
;----------------------------------------
; Enable VIC 
;---------------------------------------- 
  
   mrc p15,0,r0,c1,c0,0
   orr r0,r0,#(1<<24) ;Enable VE bit
   mcr p15,0,r0,c1,c0,0 
    
;SetBit C1 Register VE位(BIT24)则中断向量地址由VIC决定
;ClrBit C1 Register VE位(BIT24)则中断向量地址是固定地址
;  总中断ENABLE

  mrs r0,cpsr
  bic r0,r0,#0x80
  msr cpsr_c,r0
;DEBUG  
  mrs r0,cpsr
  b main

  END  
 
 
  ;-----------------------------------------------------------------------------------------------------------------------
