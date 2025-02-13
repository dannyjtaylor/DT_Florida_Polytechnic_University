module UpDownCounter(
    input clk, reset, load, up_down,
    input [3:0] data_in,
    output reg [3:0] count
);

always @(posedge clk or posedge reset) begin
    if (reset)
        count <= 4'b0000;
    else if (load)
        count <= data_in;
    else if (up_down)
        count <= count + 1;
	 else if (up_down & load)
		   //
			//count <= count+1;
    else
        count <= count - 1;
end
endmodule

//by default: period is 1 sec (1 HZ),
//have method to make it faster or slower
//can be either 1 HZ, 0.5 HZ, 2 HZ