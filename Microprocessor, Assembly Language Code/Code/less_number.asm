.model small 
.stack 100h
.data
a db ?
b db ?
.code

main proc 
    mov ah,1
    int 21h       ;Input First Number and store on bh register
    mov bh,al
    
    mov ah,1
    int 21h       ; Input second Number and store on bl registar
    mov bl,al      
    
    mov ah,2      ; Print a New Line
    mov dl,10
    int 21h
    mov dl,13
    int 21h 
      
    cmp bh,bl     ; to check if betwwen bh and bl
    jle L1         ; chceck if[ bh > bl ] then jump to L1    
    jmp L2        ; else jump to L2 
    
   
    
    L1:           ; print bh 
    mov ah, 2
    mov dl,bh
    int 21h 
    jmp exit:     ; Exit from the Code
    
    L2:           ; print bl
    mov ah, 2
    mov dl, bl
    int 21h
    
    
    exit:         ; Exit Code / Return 0
    mov ah, 4ch
    int 21h
    main endp
end main