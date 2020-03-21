.type start, %function
.global start
start:
	ldr r1, =c_entry
	bx r1
