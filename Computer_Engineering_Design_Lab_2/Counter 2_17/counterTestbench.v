`timescale 1ns/1ps

module Testbench;

// Signals for Clock Divider
reg clk_in;
reg reset;
wire clk_HALFHZ, clk_1HZ, clk_2HZ;

// Signals for Counter
reg [9:0] SW;
wire [9:0] LEDR;

// Instantiate Clock Divider
clockDividerDFF CD (
    .clk_in(clk_in),
    .reset(reset),
    .clk_HALFHZ(clk_HALFHZ),
    .clk_1HZ(clk_1HZ),
    .clk_2HZ(clk_2HZ)
);

// Instantiate Counter (Top-Level)
Counter counter_top (
    .MAX10_CLK1_50(clk_in),
    .LEDR(LEDR),
    .SW(SW)
);

// Clock Generation (50MHz)
always #10 clk_in = ~clk_in; // 50 MHz Clock


endmodule


/*
//counter testbench

`timescale 1ns/1ns

module counterTestbench(
   //registers for inputs
	reg clk;
	reg reset;
	reg load;
	reg up_down,
	reg [3:0] data_in;
	//wire for output
	wire [3:0] count;
	CounterForTestbench counter_tb (.clk(clk), .reset(reset), .load(load), .up_down(up_down), .data_in(data_in), .count(count));
);
	
	always 
	#10 clk = ~clk;
		
	initial begin
	  //test cases
	  # 0   clk = 1'b0; reset = 1'b0; load = 1'b0; data_in = 4'b0000;
	  # 160  reset = 1'b1; load = 1'b0; data_in = 4'b0000;
	  # 1    reset = 1'b0;
	  # 160 load = 1'b1; data_in = 4'b0111;
	  # 1   load = 1'b0;
	  # 90  load = 1'b1; up_down = 1'b1;
	  # 1   load = 1'b0;
	  # 40  $finish;
	end
	
	initial
	  $monitor("At time %-5t, clk = %b, reset = %b, load = %b, up_down = %b, data_in = %b, count = %b", $time, clk, reset, load, up_down, data_in, count);
endmodule

*/