//don't pay attention to this, redone to do fulladders with 4-bit ripple carry adder implementation instead of just "A+B"

module add(input [3:0] A, B, output [3:0] sum, output carryout);
	assign sum = A + B;
	assign carryout = sum > 4'b1111 ? 4'b0001 : 4'b0000;
endmodule

module multiply(input[3:0] A, B, output [7:0] product);
	assign product = A * B;
endmodule