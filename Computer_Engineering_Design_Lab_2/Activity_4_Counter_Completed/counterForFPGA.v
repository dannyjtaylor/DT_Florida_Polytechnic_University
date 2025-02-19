module Counter(
   //input as FPGA clock, switches, output as LEDR
	input 			            MAX10_CLK1_50,
	output 		     [9:0] 		LEDR,
	input 		     [9:0] 		SW
);

	 //wires needed (wires instead of input/outpu since it's using the FPGA)
	 wire reset;
	 wire load; 
	 wire up_down;
    wire [3:0] data_in;
    wire [3:0] count;
	 wire [1:0] freq_sel;
	 
	 //wires for clock
	 wire clkSelected;
	 wire clk_HALFHZ;
	 wire clk_1HZ;
	 wire clk_2HZ;
	 
	 //FPGA switch assignments
	 assign reset = SW[9];
	 assign up_down = SW[8];
	 assign load = SW[4];
	 assign data_in = SW[3:0];
	 assign freq_sel = SW[7:6];
	 
	 //FPGA LED assignments
	 assign LEDR[9] = reset;
	 assign LEDR[8] = up_down;
	 assign LEDR[4] = load;
	 assign LEDR[7:6] = freq_sel;
	 assign LEDR[3:0] = count;
	 
	 //clock divider
	 clockDividerDFF CD (.clk_in(MAX10_CLK1_50), .reset(reset), .clk_HALFHZ(clk_HALFHZ), .clk_1HZ(clk_1HZ), .clk_2HZ(clk_2HZ));
	 
	 //frequency select
    assign clkSelected = (freq_sel == 2'b00) ? clk_HALFHZ : //freq = 00, half HZ, period 2 seconds
                         (freq_sel == 2'b01) ? clk_1HZ : //freq = 01, 1HZ, period 1 second
                         (freq_sel == 2'b10) ? clk_2HZ : //freq = 10, 2HZ, period 0.5 seconds
                         clk_1HZ; //else, just make it the 1HZ clk
	
	 //updown counter
	 UpDownCounter UD1 (.clk(clkSelected), .reset(reset), .load(load), .up_down(up_down), .data_in(data_in), .count(count));
endmodule
