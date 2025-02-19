`timescale 1ns/1ns
module counter_tb;

//inputs
reg clk, reset, load, up_down;
reg [1:0] freq_sel;
reg [3:0] data_in;

//output
wire [3:0] count;
//have clock negate itself, 0, 1, 0, 1 and so on
always #1 clk = ~clk;

initial begin
	freq_sel = 2'b00; reset = 1'b0; load = 1'b0; up_down = 1'b1; data_in = 4'b0111; clk = 1'b0; //with 0.5 HZ, no reset, no load, counting up, data in set to 7, clk starts at 0
	#120 up_down = 1'b0; //count down
	#120 load = 1'b1; up_down = 1'b1; freq_sel = 2'b01; //start counting up on 1HZ, load 7
	#10 load = 1'b0; //wait a bit and stop load
	#50 reset = 1'b1; freq_sel = 2'b10; //reset it, start counting 2HZ
	#10 reset = 1'b0; //stop reset
	#100 $finish; //end
end

CounterForTestbench C1 (.clk(clk), .reset(reset), .load(load), .up_down(up_down), 
.data_in(data_in), .freq_sel(freq_sel), .count(count));

initial
	$monitor("At time %3d, reset = %b, load = %b, up_down = %b, data_in = %b, freq_sel = %b, count = %b", 
	$time, reset, load, up_down, data_in, freq_sel, count);

endmodule