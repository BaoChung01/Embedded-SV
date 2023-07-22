;;;;;;;;;;;;;;;;=========AUTO GROOT=======;;;;;;;;;;;;;;
;;;;;;;===HUONG DAN LAP TRINH VI DIEU KHIEN 8051 BANG NGON NGU ASSEMBLY======;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;====---------32 LED TRAI TIM-----=========;;;;;;;;;;;;;;;;;;;

;;;;;;;;--------------CHUONG TRINH CHINH----------;;;;;;;;;;;;;
ORG 0000H
MAIN:	
		CALL CT1
		CALL CT2
		CALL CT3
		CALL CT4
		CALL CT5
		CALL CT4
		CALL CT5
		CALL CT4
		CALL CT5		
		JMP MAIN
;;;;;;;;--------------CHUONG TRINH CON 1-----------;;;;;;;;;;;;;;
CT1:                  ;SANG VONG;
		MOV P0,#00H
		MOV P1,#00H
		MOV P2,#00H
		MOV P3,#00H		
		MOV A,#00H
LAP1:	SETB C
		RLC A
		MOV P0,A
		CALL DELAY
		CJNE A,#0FFH,LAP1
		MOV A,#00H
LAP2:	SETB C
		RLC A
		MOV P1,A
		CALL DELAY
		CJNE A,#0FFH,LAP2
		MOV A,#00H
LAP3:	SETB C
		RLC A
		MOV P2,A
		CALL DELAY
		CJNE A,#0FFH,LAP3
		MOV A,#00H
LAP4:	SETB C
		RLC A
		MOV P3,A
		CALL DELAY
		CJNE A,#0FFH,LAP4
RET
;;;;;;;;--------------CHUONG TRINH CON 2-----------;;;;;;;;;;;;;;
CT2:                  
		MOV R7,#9
LAN1:	MOV P0,#00H
		MOV P2,#00H
		MOV P1,#0FFH
		MOV P3,#0FFH
		CALL DELAY
		MOV P1,#00H
		MOV P3,#00H
		MOV P0,#0FFH
		MOV P2,#0FFH		
		CALL DELAY
RET
;;;;;;;;--------------CHUONG TRINH CON 3-----------;;;;;;;;;;;;;;
CT3:     
LAN2:	MOV P0,#01010101B
		MOV P1,#01010101B
		MOV P2,#01010101B
		MOV P3,#01010101B
		CALL DELAY
		MOV P0,#10101010B
		MOV P1,#10101010B
		MOV P2,#10101010B
		MOV P3,#10101010B
		CALL DELAY
		DJNZ R7,LAN2
RET
;;;;;;;;--------------CHUONG TRINH CON 4-----------;;;;;;;;;;;;;;
CT4:
		MOV A,#00H
LAP5:	SETB C
		RRC A
		MOV P0,A
		MOV P1,A
		MOV P2,A
		MOV P3,A
		CALL DELAY
		CJNE A,#0FFH,LAP5
RET
;;;;;;;;--------------CHUONG TRINH CON 5-----------;;;;;;;;;;;;;;
CT5:
		MOV A,#00H
LAP6:	SETB C
		RLC A
		MOV P0,A
		MOV P1,A
		MOV P2,A
		MOV P3,A
		CALL DELAY
		CJNE A,#0FFH,LAP6
RET
;;;;;;;;--------------CHUONG TRINH DELAY-----------;;;;;;;;;;;;;;
DELAY:	MOV R1,#50
LOOP1:	MOV R0,#200
LOOP2:	NOP
		NOP
		NOP
		DJNZ R0,LOOP2
		DJNZ R1,LOOP1
RET
END
;;================================================================





