.MODEL SMALL
.STACK 100h

.DATA
    inputMsg DB 'Enter a lowercase character: $'
    resultMsg DB  'Uppercase character: $'
    inputValue DB ?    ; Variable to store the input character
    resultValue DB ?   ; Variable to store the converted uppercase character

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Print prompt message
    MOV AH, 9
    LEA DX, inputMsg
    INT 21h

    ; Read input character
    MOV AH, 1
    INT 21h
    MOV inputValue, AL

    ; Convert lowercase to uppercase
    MOV AL, inputValue
    SUB AL, 32       ; Convert lowercase to uppercase

    ; Store the converted uppercase character
    MOV resultValue, AL

    ; Print the result
    MOV AH, 9
    LEA DX, resultMsg
    INT 21h

    MOV DL, resultValue
    MOV AH, 2
    INT 21h

    ; Exit the program
    MOV AH, 4Ch
    INT 21h

MAIN ENDP
END MAIN
