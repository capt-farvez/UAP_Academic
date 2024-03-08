.MODEL SMALL
.STACK 100h

.DATA
inputValue DB 'a'                  ; Lowercase ASCII character to convert

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV AL, inputValue             ; Move the ASCII character to AL

    SUB AL, 32                     ; Subtract 32 to convert lowercase to uppercase

                                   ; Print the converted uppercase character
    MOV DL, AL
    MOV AH, 2                      ; DOS interrupt function to print character
    INT 21h

    Exit:
    MOV AH, 4Ch
    INT 21h

MAIN ENDP
END MAIN
