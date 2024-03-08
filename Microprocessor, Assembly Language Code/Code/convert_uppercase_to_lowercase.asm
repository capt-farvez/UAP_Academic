.MODEL SMALL
.STACK 100h

.DATA
inputValue DB 'A'             ; Uppercase ASCII character to convert

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV AL, inputValue        ; Move the ASCII character to AL

    ADD AL, 32                ; Add 32 to convert uppercase to lowercase
                              ; Print the converted lowercase character
    MOV DL, AL
    MOV AH, 2                 ; DOS interrupt function to print character
    INT 21h

    Exit:
    MOV AH, 4Ch
    INT 21h

MAIN ENDP
END MAIN
