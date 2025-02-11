module my_counter(clk_i, rst_i, load_i, lval_i, cval_o);

	// Use of symbolic variables makes the code more readable
	localparam N=32, M=10;
	
	// Define input and output ports
	input clk_i, rst_i, load_i;
	input [M-1:0] lval_i;
	output [N-1:0] cval_o;
	
	// internal stuff (Internal physical wires & physical registers)
	wire flip;								// physical wire
	reg [N-1:0] count_r, count_n;		// physical N-bit register
	reg			dir_r,	dir_n;		// physical 1-bit register
	
	// Registers
	always@(posedge clk_i) 
	begin

	if(rst_i)    							// reset behaviour of the register		
		begin
			count_r <= 0;
			dir_r   <= 0;
		end
		else
		begin									// this part is standard
			count_r <= count_n;
			dir_r   <= dir_n;
		end
	end
	
	// Next-state logic (This is the most important section where we define the update rules)
	always @*
	begin
	
		if (load_i)	
			count_n = {lval_i, {(N-M){1'b0}}};
		else
			count_n = dir_r ? (count_r - 1) : (count_r + 1);
	
		dir_n = flip ? ~dir_r : dir_r;
		
	end
	
	assign flip = ( (count_r == 1) & (dir_r == 1) ) | ( (~count_r == 1'b1) & (dir_r == 0) );

	// Output logic
	assign cval_o = count_r;
	
endmodule 