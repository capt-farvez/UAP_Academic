.MODEL SMALL
.STACK 100H 
.DATA

X DB '?'
Y DB '?' 


STR1 DB "ENTER FIRST NUMBETR :" , 0AH, 0DH, "$"
STR2 DB 0AH, 0DH, "ENTER SECOND NUMBER : " , 0AH, 0DH, "$" 
STR3 DB 0AH, 0DH, "NUMBER IS EQUAL $"  
STR4 DB 0AH, 0DH, "NUMBER IS NOT EQUAL $"
 
.CODE
 
 
MAIN PROC
    MOV AX,@DATA   
    MOV DS,AX
    
    MOV AH,9H
    LEA DX,STR1   
    INT 21H
    
    MOV AH,1H     
    INT 21H 
    
    
    SUB AL,30H   
    MOV X,AL
         
         
    MOV AH,9H
    LEA DX,STR2   
    INT 21H 
    
    
    MOV AH,1H     
    INT 21H
    
    SUB AL, 30H  
    MOV Y,AL
                    
         
    MOV CL,X    
    
    CMP CL,Y     
    JE  EQUAL    
                 
    CMP CL,Y     
    JNE NOT
         
     
    EQUAL:     
    MOV AH,9H
    LEA DX,STR3    
    INT 21H
    
    MOV AH,2H
    ADD X, 30H
    MOV DL,X
    INT 21H
    
    JMP EXIT   
     
     
    
    NOT:
    MOV AH,9H
    LEA DX,STR4 
    INT 21h 
    
    JMP EXIT  
               
    
    EXIT:      
    MOV AH, 4CH  
    INT 21H   
   MAIN ENDP
 END MAIN 