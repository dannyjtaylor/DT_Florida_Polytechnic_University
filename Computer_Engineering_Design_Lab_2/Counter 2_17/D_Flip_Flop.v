// d flip flop
module d_ff(
	 input clk, d, reset,
	 output reg q,
	 output reg qBar
    );


    always @(posedge clk or negedge reset)
 begin
        if (!reset)
        begin
		      //if reset = 0, then clear q and make it zero
            q <= 0;
        end
        else
        begin
		  //otherwise, reset not 0, so set q to whatever d is.
            q <= d;
        end
		  qBar = ~q;
		  //set qBar (negation of q) to the opposite of q
    end

endmodule