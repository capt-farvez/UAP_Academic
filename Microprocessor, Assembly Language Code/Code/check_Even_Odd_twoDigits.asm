.MODEL SMALL
.STACK 100H

.DATA
TEXT DB "ENTER A TWO DIGIT NUMBER", 0AH, 0DH, "$"
ODD DB 0AH, 0DH, "THE NUMBER IS ODD", 0AH, 0DH, "$"
EVEN DB 0AH, 0DH, "THE NUMBER IS EVEN", 0AH, 0DH, "$"
RES DB ? 

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; TEXT OUPUT
    MOV AH, 09H
    LEA DX, TEXT
    INT 21H
    
    ; NUMBER INPUT
    MOV AH, 1H
    INT 21H
    
    SUB AL, 30H
    MOV BL, 10H
    MUL BL
    MOV RES, AL
    
    MOV AH, 1H
    INT 21H
    
    SUB AL, 30H
    ADD RES, AL
    
    ; ODD OR EVEN
    TEST RES, 1H
    JZ EVN
    ; ITS ODD THEN
    LEA DX, ODD
    JMP OD
    
    EVN:
    LEA DX, EVEN
    
    OD:
    MOV AH, 09H
    INT 21H
    
    MOV AH, 4CH
    INT 21H
    
    
    
    MAIN ENDP
END MAIN