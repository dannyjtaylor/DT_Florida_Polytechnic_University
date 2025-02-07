`timescale 1ns/1ns
module sac_tb;
    reg [3:0] A;
    wire [3:0] LogicalShift;
    wire [3:0] ArithmeticShift;
    wire [7:0] Combined;
	 
	 ShiftAndCombine U1(.A(A), .LogicalShift(LogicalShift), .ArithmeticShift(ArithmeticShift), .Combined(Combined));

    initial begin
        # 0  A = 4'b1010; 
        # 20 A = 4'b0110;
        # 20 A = 4'b0000; 
        # 20 A = 4'b0001; 
        # 20 A = 4'b0010; 
        # 20 A = 4'b0011;
        # 20 A = 4'b0100; 
        # 20 A = 4'b0101; 
        # 20 A = 4'b0110;
        # 20 A = 4'b0111;
        # 20 A = 4'b1000; 
        # 20 A = 4'b1001; 
        # 20 A = 4'b1010; 
        # 20 A = 4'b1011;
        # 20 A = 4'b1100; 
        # 20 A = 4'b1101; 
        # 20 A = 4'b1110; 
        # 20 A = 4'b1111;
        # 500 $finish;
    end
    initial
        $monitor("At time %-5t, A = %b, LogicalShift = %b, ArithmeticShift = %b, Combined = %b, Combined in Hex = %h", 
            $time, A, LogicalShift, ArithmeticShift, Combined, Combined);

endmodule