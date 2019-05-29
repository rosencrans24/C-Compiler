%include "io64.inc"
 	  	  
 	 common x 8 	 ; define a global variable 
section .data
 	  	  
section .text 	  	  
 	 global main
 	  
main: 	  	 ; Start of a function 
 	 mov rbp,rsp 	 ;special RSP to RBP for MAIN only 
 	 mov r8,rsp 	 ;FUNC header RSP is at most RBP 
 	 add r8,-64 	 ; adjust the stack pointer 
 	 mov [r8],rbp 	 ;store old BP 
 	 mov [r8+8],rsp 	 ; store old SP 
 	 mov rsp,r8 	 ;func header new SP 

 	 mov rax, 1 	 ; RHS expression is  a number 
 	 mov [rsp + 32], rax 	 ;store RHS of expression in memory 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rbx, [rsp + 32] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, 40 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rax, [rax] 	 ;RHS expression is an identifier 
 	 mov [rsp + 40], rax 	 ;store RHS of expression in memory 
 	 mov rax, 24 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rbx, [rsp + 40] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, x 	 ;load rax with location 
 	 GET_DEC 8,[rax] 	 ;Read an integer 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 GET_DEC 8,[rax] 	 ;Read an integer 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rax, [rax] 	 ;LHS expression is an identifier 
 	 mov [rsp + 56], rax 	 ;store LHS of expression in memory 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rbx, [rax] 	 ;RHS expression is an identifier 
 	 mov rax, [rsp + 56] 	 ;fetch LHS of expression from memory 
 	 add rax,rbx 	 ;EXPR ADD 
 	 mov [rsp+56],rax 	 ;store RHS of expression in memory 
 	 mov rax, [rsp + 56] 	 ; RHS is an expression 
 	 mov [rsp + 56], rax 	 ;store RHS of expression in memory 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rbx, [rsp + 56] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, x 	 ;load rax with location 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 
 	 mov rax, 24 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 

 	 mov rbp,[rsp] 	 ;Restore old BP 
 	 mov rsp,[rsp + 8] 	 ;Restore old SP 
 	 mov rsp,rbp 	 ;Special RSP and RBP restore for main 
 	 ret 	  
