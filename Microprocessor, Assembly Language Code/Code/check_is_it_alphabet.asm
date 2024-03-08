;input a charcter and test whether it is an alphabet or not. if alphabet print Alphabet else print invalid

.model small
.stack 100h
.data
alphabetMsg db 10,13,'Alphabet$'
invalidMsg db 10,13,'Invalid$'
char db ?

.code
    mov ax, @data
    mov ds, ax
                 
    mov ah, 1                   ; Read a character from the user
    int 21h
    mov char, al

    mov ah, 0                   ; Check if the character is an alphabet
    mov al, char
    cmp al, 'A'
    jb invalid
    cmp al, 'Z'
    ja lowercase
    jmp alphabet

    lowercase:
    cmp al, 'a'
    jb invalid
    cmp al, 'z'
    ja invalid
    jmp alphabet

    alphabet:                   ; Print "Alphabet"
    mov ah, 9
    lea dx, alphabetMsg
    int 21h
    jmp exit

    invalid:                    ; Print "Invalid"
    mov ah, 9
    lea dx, invalidMsg
    int 21h

    exit:
    mov ah, 4Ch
    int 21h
end
