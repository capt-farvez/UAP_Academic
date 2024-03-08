.MODEL SMALL
.STACK 100h

.DATA
    inputMsg DB 'Enter an uppercase character: $'
    resultMsg DB 'Lowercase character: $'
    inputValue DB ?                                ; Variable to store the input character
    resultValue DB ?                               ; Variable to store the converted lowercase character

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

                                                   ; Convert uppercase to lowercase
    MOV AL, inputValue
    ADD AL, 32                                     ; Convert uppercase to lowercase

                                                   ; Store the converted lowercase character
    MOV resultValue, AL

                                                   ; Print the result
    MOV AH, 9
    LEA DX, resultMsg
    INT 21h

    MOV DL, resultValue
    MOV AH, 2
    INT 21h
    MOV AH, 10H
    INT 21H

    Exit:
    MOV AH, 4Ch
    INT 21h

MAIN ENDP
END MAIN
