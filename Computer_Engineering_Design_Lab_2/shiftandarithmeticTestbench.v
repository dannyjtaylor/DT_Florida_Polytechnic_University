`timescale 1ns/1ns
module saa_tb;
	 //registers for inputs A and B
    reg [3:0] A;
	 reg [3:0] B;
	 //wires for outputs
    wire [3:0] LogicalShift;
    wire [3:0] ArithmeticShift;
    wire [7:0] Combined;
	 wire [3:0] Sum;
	 wire CarryOut;
	 wire [7:0] Product;
	 //test module
	 test U1(.A(A), .B(B), .LogicalShift(LogicalShift), .ArithmeticShift(ArithmeticShift), .Combined(Combined), .Sum(Sum), .CarryOut(CarryOut), .Product(Product));
    initial begin
		  //testcases
        # 0  A = 4'b0000; B = 4'b0000;
        # 20 A = 4'b0001; B = 4'b0001;
        # 20 A = 4'b0010; B = 4'b0010;
        # 20 A = 4'b1111; B = 4'b1111;
		  # 20 A = 4'b1010; B = 4'b1010;
		  # 20 A = 4'b1100; B = 4'b0011;
		  # 20 A = 4'b1010; B = 4'b0100;  
		  # 20 A = 4'b0011; B = 4'b0101;
		  # 20 A = 4'b1010; B = 4'b0011;
        # 300 $finish;
    end
    initial
		  //monitor testcases to verify logic
        $monitor("At time %-5t, A = %b, B = %b, LogicalShift = %b, ArithmeticShift = %b, Combined = %h, Sum = %h, CarryOut = %b, Product = %h", 
            $time, A, B, LogicalShift, ArithmeticShift, Combined, Sum, CarryOut, Product);
endmodule