%include "io64.inc"
 	  	  
section .data
 	  	  
_L0 	 db"else part", 0 	 ; global string 
section .text 	  	  
 	 global main
 	  
main: 	  	 ; Start of a function 
 	 mov rbp,rsp 	 ;special RSP to RBP for MAIN only 
 	 mov r8,rsp 	 ;FUNC header RSP is at most RBP 
 	 add r8,-56 	 ; adjust the stack pointer 
 	 mov [r8],rbp 	 ;store old BP 
 	 mov [r8+8],rsp 	 ; store old SP 
 	 mov rsp,r8 	 ;func header new SP 

 	 mov rax, 2 	 ; RHS expression is  a number 
 	 mov [rsp + 32], rax 	 ;store RHS of expression in memory 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rbx, [rsp + 32] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, 3 	 ; RHS expression is  a number 
 	 mov [rsp + 40], rax 	 ;store RHS of expression in memory 
 	 mov rax, 24 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rbx, [rsp + 40] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, 0 	 ; expression is  a number 
_L1: 	  	 ;WHILE top target 
 	 CMP rax,0 	 ;compare to end while 
 	 JE _L2 	 ;JUMP out 
 	 mov rax, 24 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 
 	 JMP _L1 	 ;JUMP to top 
_L2: 	  	 ;While bottom target 
 	 mov rax, 0 	 ;Type is a number 
 	 CMP rax,0 	 ;compare to end IF 
 	 JE _L3 	 ;JUMP else 
 	 mov rax, 24 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rax, [rax] 	 ;LHS expression is an identifier 
 	 mov [rsp + 48], rax 	 ;store LHS of expression in memory 
 	 mov rbx, 3 	 ; RHS expression is  a number 
 	 mov rax, [rsp + 48] 	 ;fetch LHS of expression from memory 
 	 cmp rax, rbx 	 ;EXPR Equal 
 	 sete al 	 ;EXPR Equal 
 	 mov rbx,1 	 ;set rbx to one to filter rax 
 	 and rax,rbx 	 ;filter RAX 
 	 mov [rsp+48],rax 	 ;store RHS of expression in memory 
 	 mov rax, [rsp + 48] 	 ;load rax if expression 
 	 CMP rax,0 	 ;compare to end IF 
 	 JE _L5 	 ;JUMP else 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 
 	 JMP _L6 	 ;jump to end 
_L5: 	  	 ;label for the else part 
 	 mov rax, 24 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 
_L6: 	  	 ;final label 
 	 JMP _L4 	 ;jump to end 
_L3: 	  	 ;label for the else part 
 	 PRINT_STRING _L0 	 ;Print a string 
 	 NEWLINE 	 ;print a newline  
 	 mov rax, 24 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 
_L4: 	  	 ;final label 

 	 mov rbp,[rsp] 	 ;Restore old BP 
 	 mov rsp,[rsp + 8] 	 ;Restore old SP 
 	 mov rsp,rbp 	 ;Special RSP and RBP restore for main 
 	 ret 	  
