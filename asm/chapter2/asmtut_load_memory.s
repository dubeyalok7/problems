.data 		
	.balign 4 @ Request 4 bytes in the address
	fifteen: @ Define storage for fifteen
		.word 0 @ Assign value to fifteen
		
	.balign 4 @ Request 4 bytes in the address
	thirty: @ Define storage for thirty
		.word 0 @ Assign value to thirty
	
	.text
	.global _start
	_start:
    	LDR R1, addr_fifteen @ Load address
    	MOV R3, #15 @ Put 15 in R3
    	STR R3, [R1] @ Put value in R3 at the address in R1
    	LDR R2, addr_thirty @ Load address
    	MOV R3, #30 @ Put 30 in R3
    	STR R3, [R2] @ Put value in R3 at the address in R2
    	
    	@ Redo last program
    	LDR R1, addr_fifteen @ Load address
    	LDR R1, [R1] @ Load data using address
    	LDR R2, addr_thirty @ Load address
    	LDR R2, [R2] @ Load data using address
    	ADD R0, R1, R2
    	
	end:
		MOV R7, #1 
		SWI 0
    	
	@ Labels for addresses in the data section
	addr_fifteen : .word fifteen
	addr_thirty : .word thirty
