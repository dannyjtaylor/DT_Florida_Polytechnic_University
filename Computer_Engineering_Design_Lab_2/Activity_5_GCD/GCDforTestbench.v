module GCDforTestbench(
    input clk, reset, load,
    input [4:0] A_in,
    input [4:0] B_in,
    output [4:0] GCD_out,
    output done
);
    GCD_Compute G1(.clk(clk), .reset(reset), .load(load), .A_in(A_in), .B_in(B_in), .GCD_out(GCD_out), .done(done));
endmodule

module GCD_Compute(
    input clk, reset, load,
    input [4:0] A_in,
    input [4:0] B_in,
    output reg [4:0] GCD_out,
    output reg done
);
    //temporary registers needed	 
    reg [4:0] A, B;
	 //sequential logic to update for reset or rising edge of clock
    always @(posedge clk or posedge reset) begin
		  //if reset, make GCD zero, set done LOW, make A, B zero
        if (reset) begin
            GCD_out <= 0;
            done <= 0;
            A <= 0;
            B <= 0;
        end 
        else if (load) begin
            //make temporary register A the larger value of the two (if need be)
            if (A_in >= B_in) begin
                A <= A_in;
                B <= B_in;
					 done <= 0;
            end else begin
                A <= B_in;
                B <= A_in;
					 done <=0;
            end
            done <= 0;
        end 
        else if (B != 0) begin
		  //if B not equal to 0, follow GCD algorithm
            A <= B;
            B <= A % B;
				done <= 0;
        end 
        else begin
		  //else, B is 0, so GCD is A, and set done to 1
            GCD_out <= A;
            done <= 1;
        end
    end
endmodule