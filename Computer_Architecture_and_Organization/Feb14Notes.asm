# Comp Arch Notes 2/14/2025

# C code for Factorial
#int fact (int n) {
#	if (n<1) return f;
#	else return n * fact(n-1)
#} argument n in $a0, result in $v0




# stack     - $ra (main) - > $ao = 3 (SP)
#stack for a0 = 2 : $ra (main) 
#
#   $ra (2)
#   $a0 = 3
#   $ra (main)
#procedure

fact: 
	addi $sp, $sp, -8  #adjust stack for 2 items (a0 and sp)
	sw $ra, 4($sp)     #at beginning, save return address and save the argument. at each instance, return address and argument changes. use offset of 4 to have sp move 2 times down in stack
	sw $a0, 0($sp)
	slti $t0, $a0, 1    #test for n<1      
       beq $t0, $zero, L1  #branch if it's not 1 (t0 = 0)
       addi $v0, $zero, 1  #if so, result is 1
       addi $sp, $sp, 8    #pop 2 items from stack
       jr $ra              #and return
L1:    addi $a0, $a0, -1  #else, decerement n
       jal fact #recursive call (makes a new $ra in stack)
       lw $a0, 0($sp) # restore original n and return address
       lw $ra, 4($sp)
       addi $sp, $sp, 8 # pop 2 items from stack
       mul $v0, $a0, $v0 #multiply a0 and v0 to get result
       jr $ra
       
       
       # once L1 isn't called, recursion is done. v0 = 1, stack pointer decreased by 2, then we jump and return to $ra. $ra updates each recursive call. it jumps to the 2 load word instructions, that's where $ra is.
       #lw, a0 = 1. it jumps from then a0 = 0, and the most recent ra to the next-most recent (where a0 is 1)
       # lw, ra = ra1
       # updates v0 to a0 * v0, (1 * 1). v0 comes from the last call (w/ a0 = 0)
       
       
       #this happens again, a0 will be 2, v0 = 1 * 2 = 2,
       #and again, a0 will be 3, v0 = 2 * 3 = 6. 3! = 3 * 2 * 1 = 6. 
       
       #each load word set loads the original value of n (basically n from the previous recurisve call), and the previous $ra.
       #then adds SP by 8 to pop 2 items at once.
       #remember that the respect a0 and $ra update each time at every recursive call, even if they're the same registers. stack saves all the values
       
       
       #very last time jr to $ra is called, that's the actual $ra to main 

