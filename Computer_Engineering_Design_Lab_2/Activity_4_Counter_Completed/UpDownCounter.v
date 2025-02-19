module UpDownCounter(
	 //inputs needed
    input clk, reset, load, up_down,
    input [3:0] data_in,
	 //output needed
    output reg [3:0] count
);
always @(posedge clk or posedge reset) begin
    //if reset, make count 0
    if (reset)
        count <= 4'b0000;
    else if (load)
	     //if load = 1, then set count to the data coming in
        count <= data_in;
    else if (up_down)
			//if up_down = 1, then count up
        count <= count + 1;
    else
		  //else, count down (up_down = 0, load = 0, reset = 0)
        count <= count - 1;
end
endmodule