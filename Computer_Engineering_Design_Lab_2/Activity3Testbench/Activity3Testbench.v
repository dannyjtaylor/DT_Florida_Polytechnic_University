module shiftandarithmeticForTestbench(
   input [3:0] A, B,
	output [3:0] LogicalShift,
	output [3:0] ArithmeticShift,
	output [7:0] Combined,
	output [3:0] Sum,
	output CarryOut,
	output [7:0] Product);
	
	
	//logical shift to the left
	assign LogicalShift = A << 1;
	//arithmetic shift to the right
	assign ArithmeticShift = $signed(A) >>> 1;
	//concatenation of A and Logical Shift result
	assign Combined = {A, LogicalShift};
	//addition
	
	add a2(.A(A), .B(B), .sum(Sum), .carryout(CarryOut));
	
	multiply m2(.A(A), .B(B), .product(Product));
endmodule