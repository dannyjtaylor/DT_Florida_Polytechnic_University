// testbench for simulation

`timescale 1ns/1ps

module my_testbench;

	reg clk, rst, load;
	reg [9:0] lval;

	initial begin
	  clk = 0; rst = 1; load = 0;
	  # 13 	rst = 0;
	  # 50	load = 1; lval = 10'b11_1111_1100;
	  # 10   load = 0;
	  # 100 	$stop;
	end

	wire [31:0] probe;
	wire [ 9:0] ledr; 
	my_counter U1(.clk_i(clk), .rst_i(rst), .load_i(load), .lval_i(lval), .cval_o(probe));
	assign ledr = probe[31:22];

	always 
		#5 clk = !clk;

	/*
	initial
	  $monitor("At time %-5t, ledr = 10'b%010b", $time, ledr);
	*/
	
	/*  
	initial
	begin
		$dumpfile("my_simulation.vcd");
		$dumpvars(0, my_testbench);
	end
	*/
	
endmodule