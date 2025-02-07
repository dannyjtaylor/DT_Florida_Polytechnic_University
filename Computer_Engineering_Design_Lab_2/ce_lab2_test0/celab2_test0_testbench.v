`timescale 1ns/1ns
module test0_tb;
    reg  [9:0]  SW;
    wire [9:0]  LEDR;
    initial begin
		# 0 SW = 10'b0000000000;
		# 20 SW = 10'b0000000001;
      # 20 SW = 10'b0001000010;
      # 20 SW = 10'b0101110101;
      # 20 SW = 10'b0110111010;
      # 20 SW = 10'b1000000000;
      # 20 SW = 10'b0010101110;
      # 20 SW = 10'b1111111111;
		# 500 $finish;
		end
	 ce_lab2_test0 U1(.SW(SW), .LEDR(LEDR));
		  initial
    $monitor("At time %-5t, SW = %b, LEDR = %b", $time, SW, LEDR);
endmodule
