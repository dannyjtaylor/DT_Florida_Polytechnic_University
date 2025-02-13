module add(input [3:0] A, B, output [3:0] sum, output carryout);
	//4-bit ripple carry adder implementation
	wire carry[2:0];
	fulladder SFA1(A[0], B[0], 0, sum[0], carry[0]);
	fulladder SFA2(A[1], B[1], carry[0], sum[1], carry[1]);
	fulladder SFA3(A[2], B[2], carry[1], sum[2], carry[2]);
	fulladder SFA4(A[3], B[3], carry[2], sum[3], carryout);
endmodule

module multiply(input [3:0] A, B, output [7:0] product);
	//multiplier circuit implementation
	//wires needed
	wire [3:0] carry0;
	wire [3:0] carry1;
	wire [2:0] carry2;
	wire [5:0] sumIn;

	//P0
	assign product[0] = A[0] & B[0];

	//P1
	halfadder MHA1((A[1] & B[0]), (A[0] & B[1]), product[1], carry0[0]);

	//P2
	fulladder MFA1((A[2] & B[0]), (A[1] & B[1]), carry0[0], sumIn[0], carry0[1]);
	halfadder MHA2(sumIn[0], (A[0] & B[2]), product[2], carry1[0]);

	//P3
	fulladder MFA2((A[3] & B[0]), (A[2] & B[1]), carry0[1], sumIn[1], carry0[2]);
	fulladder MFA3((A[1] & B[2]), sumIn[1], carry1[0], sumIn[2], carry1[1]);
	halfadder MHA3(sumIn[2], (A[0] & B[3]), product[3], carry2[0]);

	//P4 (Matching the diagram with half-adder + two full-adders)
	halfadder MHA4((A[3] & B[1]), carry0[2], sumIn[3], carry0[3]);  // First half-adder
	fulladder MFA4(sumIn[3], (A[2] & B[2]), carry1[1], sumIn[4], carry1[2]);  // First full-adder
	fulladder MFA5(sumIn[4], (A[1] & B[3]), carry2[0], product[4], carry2[1]);  // Second full-adder

	//P5
	fulladder MFA6((A[3] & B[2]), carry0[3], carry1[2], sumIn[5], carry1[3]);
	fulladder MFA7(sumIn[5], (A[2] & B[3]), carry2[1], product[5], carry2[2]);

	//P6, P7
	fulladder MFA8((A[3] & B[3]), carry1[3], carry2[2], product[6], product[7]);	

endmodule

module fulladder(input a, b, cin, output s, c); 
	//fulladder sum output
	assign s = ((a ^ b) ^ cin);
	//fulladder carry output
	assign c = (a & b) | (cin & (a ^ b));
endmodule

module halfadder(input a, b, output s, c); 
	//halfadder sum output
	assign s = (a ^ b);
	//halfadder carry output
	assign c = a & b;
endmodule