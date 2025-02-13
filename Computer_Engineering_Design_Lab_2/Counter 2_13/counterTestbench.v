//counter testbench

`timescale 1ns/1ns

module counterTestbench(
   //registers for inputs
	reg clk, reset, load, up_down;
	reg [3:0] data_in;
	//wire for output
	wire [3:0] count;
	
	CounterForTestbench counter_tb(.clk(clk), .reset(reset), .load(load), .up_down(up_down), .data_in(data_in), .count(count));

	initial begin
	  //testcases
	  # 0   clk = 1'b0; reset = 1'b0; load = 1'b0; data_in = 4'b0000;
	  # 80  reset = 1'b1; load = 1'b0; data_in = 4'b0000;
	  # 80 load = 1'b1; data_in = 4'b0111;
	  # 45  load = 1'b1; up_down = 1'b1;
	  # 20  $finish;
	end

	always 
		#5 clk = ~clk;

	initial
	  $monitor("At time %-5t, clk = %b, reset = %b, load = %b, up_down = %b, data_in = %b, count = %b", $time, clk, reset, load, up_down, data_in, count);
endmodule