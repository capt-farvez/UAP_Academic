.MODEL SMALL
.STACK 100H

.DATA
TEXT DB "ENTER A SINGLE DIGIT NUMBER", 0AH, 0DH, "$"
ODD DB 0AH, 0DH, "THE NUMBER IS ODD", 0AH, 0DH, "$"
EVEN DB 0AH, 0DH, "THE NUMBER IS EVEN", 0AH, 0DH, "$"
RES DB ? 

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; Display prompt message
    MOV AH, 9H
    LEA DX, TEXT
    INT 21H
    
    ; Read the input digit
    MOV AH, 1H
    INT 21H
    SUB AL, '0'
    MOV RES, AL
    
    ; Check if the number is odd or even
    TEST RES, 1H
    JZ EVN
    
    ; It's odd, display the message
    MOV AH, 9H
    LEA DX, ODD
    JMP PRINT
    
EVN:
    ; It's even, display the message
    MOV AH, 9H
    LEA DX, EVEN
    
PRINT:
    INT 21H
    
    ; Exit the program
    MOV AH, 4CH
    INT 21H
    
MAIN ENDP
END MAIN
