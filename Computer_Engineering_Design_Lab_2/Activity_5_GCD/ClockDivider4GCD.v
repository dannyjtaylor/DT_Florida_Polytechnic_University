module clockDividerDFF (
//inputs are clk_in (FPGA clock) and clkGCD is the output clock for GCD
    input clk_in, reset,
    output reg clkGCD
);
    reg [31:0] clockCycle; //32 bit counter to count clock cycles

	 //clock divider
    always @(posedge clk_in or posedge reset) 
	 begin
        if (reset) 
		  begin
		  //at reset, make all the clocks and current number of clock cycles 0
            clockCycle <= 0;
            clkGCD <= 0;
        end 
		  else 
		  begin
				//increment a clockcycle counter for each clock cycle
            clockCycle <= clockCycle + 1;
            
            //toggle the clock sent to FPGA whenever the right amount of clock cycles is reached 
            if ((clockCycle % (10000000/2)) == 0) 
				begin
                clkGCD <= ~clkGCD;
            end
            //reset counter whenever largest amt of clock cycles needed is reached
            if (clockCycle >= 10000000) 
				begin
                clockCycle <= 0;
            end
        end
    end
endmodule
