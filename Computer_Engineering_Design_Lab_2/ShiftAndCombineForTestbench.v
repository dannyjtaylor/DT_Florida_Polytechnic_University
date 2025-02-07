module ShiftAndCombine(
   input [3:0] A,
	output [3:0] LogicalShift,
	output [3:0] ArithmeticShift,
	output [7:0] Combined);
	
	//Logic
	
	//logical shift to the left
	assign LogicalShift = A << 1;
	//arithmetic shift to the right
	assign ArithmeticShift = $signed(A) >>> 1;
	
	//concatenation of A and Logical Shift result
	assign Combined = {A, LogicalShift};
endmodule