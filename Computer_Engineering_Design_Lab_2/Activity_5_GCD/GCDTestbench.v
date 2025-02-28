`timescale 1ns/1ns
module gcd_tb;
    reg clk, reset, load;
    reg [4:0] A_in;
    reg [4:0] B_in;
    wire [4:0] GCD_out;
    wire done;
	 //create GCD module
    GCDforTestbench GCD (.clk(clk), .reset(reset), .load(load), .A_in(A_in), .B_in(B_in), .GCD_out(GCD_out), .done(done));
	 //always statement for 10 ns clock period
    always #5 clk = ~clk;
    initial begin
	     //test reset so A, B, GCD is 0
        #0 clk = 0; reset = 1; load = 0; A_in = 5'b00000; B_in = 5'b00000;
		  //GCD(20,15)
        #10 reset = 0; A_in = 5'b10100; B_in = 5'b01111; load = 1;
		  //load and observe
        #10 load = 0; #30
		  //reset and wait
		  #10 reset = 1; #10 reset = 0;
		  
		  //GCD(30,10)
        #10 A_in = 5'b11110; B_in = 5'b01010; load = 1;
		  //load and observe
        #10 load = 0; #30
		  //reset and wait
		  #10 reset = 1; #10 reset = 0;
		  
		  //GCD(12,16)
		  #10 A_in = 5'b01100; B_in = 5'b10000; load = 1;
		  //load and observe
        #10 load = 0; #30
		  	//reset and wait
		  #10 reset = 1; #10 reset = 0;
		  
		  //GCD(21,18)
        #10 A_in = 5'b10101; B_in = 5'b10010; load = 1;
		  //load and observe
        #10 load = 0; #30
		  #10 $finish;
    end
    initial begin
        $monitor("At time %-5t, clk=%b, reset=%b, load=%b, A_in=%b, B_in=%b, GCD_out=%b, done=%b", 
        $time, clk, reset, load, A_in, B_in, GCD_out, done);
    end
endmodule