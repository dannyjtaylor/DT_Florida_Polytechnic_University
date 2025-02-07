# addi $t0, $zero, 10
# subi $s2, $t0, 2


# for(i = 0; i<100; i++) {
#     result = result + A[i]
#}
# i in $t1, result in $s2, base address of A in $s0

	addi $t1, $zero, 0     #i = 0
loop:
	sll $t0, $t1, 2        # multiply i by 4 to calculate offset           #
	add $t0, $s0, $t0                                                      # getting A[i]
	lw $t2, 0($t0)         #load A with index (i*4) + base address         #
	
	add $s2, $s2, $t2 	#result = result + A[i]
	
	addi $t1, $t1, 1 	#increment i
	
	slti $t4, $t1, 100     #check if i < 100
	bne $t4, $zero, loop   #if 0, then i is not < 100, so jump to exit


#Rawa's Version
	addi $t1, $zero, 0 # step 1, i = 0
	
loop: 	lw $t0, 0($s0)     #step 2, A[i], this loads A into t0 at first, and then A[i]. it's fine since i = 0 at first
	addi $s0, $s0, 4   #increase by 4 each time
	
	add $s2, $s2, $t0
	addi $t1, $t1, 1
	slti $t3, $t1, 100
	bne $t3, $zero, loop



# yo dont use load immediate (LI) orsubi
# use instructions from data sheet