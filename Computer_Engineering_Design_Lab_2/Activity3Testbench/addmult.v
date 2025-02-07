module add(input [3:0] A, B, output [3:0] sum, output carryout);
	//5 bits for sum (since ultimately it could be up to 5 bits)
	wire [5:0] Sum = A+B;
	//first 4 bits are the actual sum
	assign sum = Sum[3:0];
	//5th bit (MSB) is the carry
	assign carryout = Sum[4];
endmodule

module multiply(input[3:0] A, B, output [7:0] product);
	//compute product
	assign product = A * B;
endmodule