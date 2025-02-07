`timescale 1ns/1ns
module saa_tb;
    reg [3:0] A;
	 reg [3:0] B;
    wire [3:0] LogicalShift;
    wire [3:0] ArithmeticShift;
    wire [7:0] Combined;
	 wire [3:0] Sum;
	 wire CarryOut;
	 wire [7:0] Product;
	 
	 
	 shiftandarithmeticForTestBench uut (.A(A), .B(B), .LogicalShift(LogicalShift), .ArithmeticShift(ArithmeticShift), .Combined(Combined), .Sum(Sum), .CarryOut(CarryOut), .Product(Product));

    initial begin
        # 0  A = 4'b0000; B = 4'b0000;
        # 20 A = 4'b0001; B = 4'b0001;
        # 20 A = 4'b0010; B = 4'b0010;
        # 20 A = 4'b1111; B = 4'b1111;
		  # 20 A = 4'b1010; B = 4'b1010;
		  # 20 A = 4'b1100; B = 4'b0011;
		  # 20 A = 4'b0011; B = 4'b0101;
		  # 20 A = 4'b1010; B = 4'b0100;
        # 260 $finish;
    end
    initial
        $monitor("At time %-5t, A = %b, LogicalShift = %b, ArithmeticShift = %b, Combined = %b, Combined in Hex = %h, Sum = %b, Sum in Hex = %h, CarryOut = %b, Product = %b, Product in Hex = %h", 
            $time, A, LogicalShift, ArithmeticShift, Combined, Combined, Sum, Sum, CarryOut, Product, Product);

endmodule