module GCD(
    input MAX10_CLK1_50,
    input [1:0] KEY,
    output [9:0] LEDR,
    input [9:0] SW
);
    wire clk, reset, start;
    wire [4:0] A_in;
    wire [4:0] B_in;
    wire [4:0] GCD_out;
    wire done;
	 //buttons for reset/load
    assign reset = ~KEY[0];
    assign load = ~KEY[1];
	 //switches for A and B
    assign A_in = SW[4:0];
    assign B_in = SW[9:5];
	 //LEDR for GCD and done light
	 assign LEDR[4:0] = GCD_out;
    assign LEDR[9] = done;
	 //clock divider since FPGA 50MHz clk is too fast
	 clockDividerDFF CDGCD (.clk_in(MAX10_CLK1_50), .reset(reset), .clkGCD(clk));
	 //module to compute GCD
    GCD_Compute G1 (.clk(clk), .reset(reset), .load(load), .A_in(A_in), .B_in(B_in), .GCD_out(GCD_out), .done(done));
endmodule