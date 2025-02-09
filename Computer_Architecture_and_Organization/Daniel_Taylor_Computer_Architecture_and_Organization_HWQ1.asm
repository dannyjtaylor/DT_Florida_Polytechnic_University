# program 2
# Z = (A + B) X (C-D) A = 2, B = 4, C = 6, D = 3, Z = (2+4) * (6-3) = 6 * 3 = 18, Z should be 18. 
#use PEMDAS, so parenthesis first, and then use mult from MIPS reference sheet to multiply

addi $s1, $zero, 2  # A = 2
addi $s2, $zero, 4   # B = 4
addi $s4, $zero, 6   # C = 6
addi $s3, $zero, 3,  # D = 3
add $t0, $s1, $s2    # t0 = A + B 
sub $t1, $s4, $t3    # t1 = C - D 
mul $s5, $t0, $s1    # Z = (A+B) * (C-D)
