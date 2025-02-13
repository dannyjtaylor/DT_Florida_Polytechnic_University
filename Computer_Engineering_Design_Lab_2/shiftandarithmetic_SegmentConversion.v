//Binary to BCD Conversion

module convert(input [3:0] halfbyte, output reg [7:0] seg);

//usse always block with the * symbol for sensitivity list
    always @ (*) begin
	 
	 //verilog case statement
        case (halfbyte)
		  //checks the hex-code of the halfbyte and decodes it to be displayed on the 7-seg
            4'h0: seg = 8'b11000000;
            4'h1: seg = 8'b11111001;
            4'h2: seg = 8'b10100100;
            4'h3: seg = 8'b10110000;
            4'h4: seg = 8'b10011001;
            4'h5: seg = 8'b10010010;
            4'h6: seg = 8'b10000010;
            4'h7: seg = 8'b11111000;
            4'h8: seg = 8'b10000000;
            4'h9: seg = 8'b10010000;
				4'ha: seg = 8'b10001000;
            4'hb: seg = 8'b10000011;
            4'hc: seg = 8'b11000110;
            4'hd: seg = 8'b10100001;
				4'he: seg = 8'b10000110;
				4'hf: seg = 8'b10001110;
				
				//default, have seven-segment display be completely off
            default: seg = 8'b11111111;
        endcase 
    end
endmodule


//7-Seg Decoder for the Carry

module convertCarry(input carry, output reg [7:0] seg);

//usse always block with the * symbol for sensitivity list
    always @ (*) begin
	 
	 //verilog case statement
        case (carry)
		  //checks the hex-code of the halfbyte and decodes it to be displayed on the 7-seg
            1'b0: seg = 8'b11000000;
            1'b1: seg = 8'b11111001;
				
				//default, have seven-segment display be completely off
            default: seg = 8'b11111111;
        endcase 
    end
endmodule