module CE_Lab2_Counter(

	//////////// CLOCK //////////
	input 		          		ADC_CLK_10,
	input 		          		MAX10_CLK1_50,
	input 		          		MAX10_CLK2_50,

	//////////// SEG7 //////////
	output		     [7:0]		HEX0,
	output		     [7:0]		HEX1,
	output		     [7:0]		HEX2,
	output		     [7:0]		HEX3,
	output		     [7:0]		HEX4,
	output		     [7:0]		HEX5,

	//////////// KEY //////////
	input 		     [1:0]		KEY,

	//////////// LED //////////
	output		     [9:0]		LEDR,

	//////////// SW //////////
	input 		     [9:0]		SW
);


wire [31:0] cval;

my_counter U1(
					.clk_i(ADC_CLK_10), .rst_i(~KEY[0]), .load_i(~KEY[1]),
					.lval_i(SW),
					.cval_o(cval)
				);

assign LEDR = cval[31:20];

assign HEX0 = 8'b1111_1111;
assign HEX1 = 8'b1111_1111;
assign HEX2 = 8'b1111_1111;
//assign HEX3 = 8'b1111_1111;
//assign HEX4 = 8'b1111_1111;
//assign HEX5 = 8'b1111_1111;

//SEG7_LUT UH0(.oSEG(HEX0), .iDIG(cval[11:08]));
//SEG7_LUT UH1(.oSEG(HEX1), .iDIG(cval[17:12]));
//SEG7_LUT UH2(.oSEG(HEX2), .iDIG(cval[19:16]));
SEG7_LUT UH3(.oSEG(HEX3), .iDIG(cval[23:20]));
SEG7_LUT UH4(.oSEG(HEX4), .iDIG(cval[27:24]));
SEG7_LUT UH5(.oSEG(HEX5), .iDIG(cval[31:28]));

				
endmodule
