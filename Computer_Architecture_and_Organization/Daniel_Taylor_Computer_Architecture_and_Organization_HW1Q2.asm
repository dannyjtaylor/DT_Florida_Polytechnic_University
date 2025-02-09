# program 1
# Z = A - (B+D) - C, A = 13, B = 2, D = 7, C = 2, Z = 13 - (2+7) - 2 = 2, Z should be 2. 
#use only $t0 for a temporary register

#use PEMDAS, so parenthesis first, and then subtraction left to right

addi $s1, $zero, 13  # A = 13
addi $s2, $zero, 2   # B = 2
addi $s3, $zero, 7   # D = 7
addi $s4, $zero, 2,  # C = 2
add $t0, $s2, $s3    # t0 = B + D 
sub $t0, $s1, $t0    # t0 = A - (B+D)
sub $s5, $t0, $s4    # Z = t0 - C    =   A-(B+D) - C
