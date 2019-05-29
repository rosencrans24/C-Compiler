%include "io64.inc"
 	  	  
section .data
 	  	  
section .text 	  	  
 	 global main
 	  
main: 	  	 ; Start of a function 
 	 mov rbp,rsp 	 ;special RSP to RBP for MAIN only 
 	 mov r8,rsp 	 ;FUNC header RSP is at most RBP 
 	 add r8,-848 	 ; adjust the stack pointer 
 	 mov [r8],rbp 	 ;store old BP 
 	 mov [r8+8],rsp 	 ; store old SP 
 	 mov rsp,r8 	 ;func header new SP 

 	 mov rax, 1 	 ; RHS expression is  a number 
 	 mov [rsp + 816], rax 	 ;store RHS of expression in memory 
 	 mov rbx, 0 	 ; RBX is a number 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rsp + 816] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, 2 	 ; RHS expression is  a number 
 	 mov [rsp + 824], rax 	 ;store RHS of expression in memory 
 	 mov rbx, 1 	 ; RBX is a number 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rsp + 824] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, 3 	 ; RHS expression is  a number 
 	 mov [rsp + 832], rax 	 ;store RHS of expression in memory 
 	 mov rbx, 2 	 ; RBX is a number 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rsp + 832] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rax, 0 	 ; RHS expression is  a number 
 	 mov [rsp + 840], rax 	 ;store RHS of expression in memory 
 	 mov rbx, 3 	 ; RBX is a number 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rsp + 840] 	 ;Load RHS into RBX 
 	 mov [rax],rbx 	 ;Store RHS 
 	 mov rbx, 1 	 ; RBX is a number 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rax] 	 ;store ident value in rbx 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rax] 	 ;store ident value in rbx 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rax] 	 ;store ident value in rbx 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rbx, [rax] 	 ;store ident value in rbx 
 	 shl rbx, 3 	 ;multiply RBX by 3 
 	 mov rax, 16 	 ;Load RAX with location 
 	 add rax,rsp 	 ; add RAX and RSP 
 	 add rax,rbx 	 ;adds RBX to RAX 
 	 mov rsi,[rax] 	 ;Load RSI 
 	 PRINT_DEC 8,rsi 	 ;Print 
 	 NEWLINE 	 ;Newline 

 	 mov rbp,[rsp] 	 ;Restore old BP 
 	 mov rsp,[rsp + 8] 	 ;Restore old SP 
 	 mov rsp,rbp 	 ;Special RSP and RBP restore for main 
 	 ret 	  
