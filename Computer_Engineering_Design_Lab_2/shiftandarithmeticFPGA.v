module shiftandarithmeticFPGA(

//FOR FPGA BOARD DATA DIRECTION
	//////////// SEG7 //////////
	output		     [7:0]		HEX0,
	output		     [7:0]		HEX1,
	output		     [7:0]		HEX2,
	output		     [7:0]		HEX3,
	output		     [7:0]		HEX4,
	output		     [7:0]		HEX5,

	//////////// LED //////////
	output		     [9:0]		LEDR,

	//////////// SW //////////
	input 		     [9:0]		SW);
	
   //inputs and outputs	
   wire [3:0] A;
	wire [3:0] B;
	wire [3:0] LogicalShift;
	wire [3:0] ArithmeticShift;
	wire [7:0] Combined;
	wire [3:0] Sum;
	wire CarryOut;
	wire [7:0] Product;
	
	//assign switches
	assign A = SW[3:0];
	assign B = SW[7:4];
	
	//logical shift to the left
	assign LogicalShift = A << 1;
	assign LEDR[3:0] = LogicalShift;
	
	//arithmetic shift to the right
	assign ArithmeticShift = $signed(A) >>> 1;
	assign LEDR[7:4] = ArithmeticShift;
	
	//concatenation of A and Logical Shift result
	assign Combined = {A, LogicalShift};
	//put A on 2nd hex display, and then the logical shift on the 1st hex display
	convert dispCombine(A, HEX1);
	convert dispCombine2(LogicalShift, HEX0);
	
	
	//Sum
	add a1(.A(A), .B(B), .sum(Sum), .carryout(CarryOut));
	
	multiply m1 (.A(A), .B(B), .product(Product));
	
	//combined hex display
	convert dispAdd(Sum, HEX2);
	convertCarry dispCarry(CarryOut, HEX3);
	
   convert dispProduct1(Product[3:0], HEX4);
	convert dispProduct2(Product[7:4], HEX5);
endmodule