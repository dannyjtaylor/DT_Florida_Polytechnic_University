module clockDividerDFF (
//inputs are clk_in (FPGA clock) and reset, outputs are the corresponding half HZ, 1HZ, and 2HZ clocks
    input clk_in, reset,
    output reg clk_HALFHZ,
    output reg clk_1HZ,
    output reg clk_2HZ
);
    reg [31:0] clockCycle; //32 bit counter to get up to 50 mil

	 //clock divider
    always @(posedge clk_in or posedge reset) 
	 begin
        if (reset) 
		  begin
		  //at reset, make all the clocks and current number of clock cycles 0
            clockCycle <= 0;
            clk_HALFHZ <= 0;
            clk_1HZ <= 0;
            clk_2HZ <= 0;
        end 
		  else 
		  begin
				//increment a clockcycle counter for each clock cycle
            clockCycle <= clockCycle + 1;
            
            //toggle the clock sent to FPGA whenever the right amount of clock cycles is reached
				if ((clockCycle % (100000000*2)) == 0) 
				begin
                clk_HALFHZ <= ~clk_HALFHZ;
            end
				
				if ((clockCycle % (100000000)) == 0)
				begin
                clk_1HZ <= ~clk_1HZ;
            end
				
            if ((clockCycle % (50000000/2)) == 0) 
				begin
                clk_2HZ <= ~clk_2HZ;
            end
            
            //reset counter whenever largest amt of clock cycles needed is reached
            if (clockCycle >= 200000000) 
				begin
                clockCycle <= 0;
            end
        end
    end
endmodule
