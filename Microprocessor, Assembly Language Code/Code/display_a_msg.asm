 ;DISPLAY A MSG  

.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 'Hello !$'
  
.CODE

MAIN PROC 
     MOV AX,@DATA
     MOV DS,AX 
     
     MOV AH,9H
     LEA DX,MSG1
     INT 21H
       
    MAIN ENDP 

END MAIN