;Input a charcter and test whether it is a number or not. if number print Number else print invalid

.model small
.stack 100h

.data
    message db 10,13,'Enter a character: $'
    numberMsg db 10,13,'Number$'
    invalidMsg db 10,13,'Invalid$'
    char db ?

.code
    mov ax, @data
    mov ds, ax

    ; Print the message to enter a character
    mov ah, 9
    lea dx, message
    int 21h

    ; Read a character from the user
    mov ah, 1
    int 21h
    mov char, al

    ; Check if the character is a number
    mov ah, 0
    mov al, char
    cmp al, '0'
    jb invalid
    cmp al, '9'
    ja invalid

    ; Print "Number"
    mov ah, 9
    lea dx, numberMsg
    int 21h
    jmp exit

invalid:
    ; Print "Invalid"
    mov ah, 9
    lea dx, invalidMsg
    int 21h

exit:
    mov ah, 4Ch
    int 21h
end
