/*
Gustavo Alejandro Solorio Ramos
email: gustavo.solorio@iteso.mx
Laboratory Exercise 1
Switches, Lights, and Multiplexers 
Part V 
Description: Multiplexer exercise that rotates "HELP" word, which is introduced by 2 switches
______________________
|SW 1|SW0 	|Character	|
|0	|0 	|	H			|
|0	|1 	|	E			|
|1	|0 	|	L			|
|1	|1 	|	P			|
---------------------
Table 1. Character codes for each display [HEX3 to HEX0], the SW combination is asociated to SEL0 to SEL3 in this code
_______________________________
|SW9|SW8|HEX4	HEX3	HEX2	HEX|
|0	| 0  | H		  E	 L		 P |
|0	| 1  | E		  L	 P		 H |
|1	| 0  | L		  P	 H	    E |
|1	| 1  | P		  H    E		 L |
-------------------------------
Table 2. Rotating the word HELP on four displays 
*/

module P1_V(
//=======================================================
//  Input / Output declarations
//=======================================================

	//////////// SW //////////
input [9:0] SW,
	//////////// SEG7 //////////
output [6:0] HEX0,
output [6:0] HEX1,
output [6:0] HEX2,
output [6:0] HEX3
);

//=======================================================
//  REG/WIRE & Parameter declarations
//=======================================================
wire [1:0] Multiplexer;
wire [1:0] Switch_H0;
wire [1:0] Switch_H1;
wire [1:0] Switch_H2;
wire [1:0] Switch_H3;

reg [8:0] ChangeSW;  //Contains the switch position to change the order of the character
reg [6:0] H0;			//Store the BCD code for each Display
reg [6:0] H1;			//Store the BCD code for each Display
reg [6:0] H2;			//Store the BCD code for each Display
reg [6:0] H3;			//Store the BCD code for each Display

parameter H = 7'b0001001;	//Define BCD code for H character
parameter E = 7'b0000110;	//Define BCD code for E character
parameter L = 7'b1000111;	//Define BCD code for L character
parameter P = 7'b0001100;	//Define BCD code for P character

//=======================================================
// Assignments
//=======================================================

assign Multiplexer = SW[9:8];  		//Assigning switches 9:8 as for multiplexer selection

assign Switch_H0 = ChangeSW[1:0];		//**********************************************************
assign Switch_H1 = ChangeSW[3:2];		//* 
assign Switch_H2 = ChangeSW[5:4];		//*The SEL switches for each display take te value of the auxiliar variable, and will rotate for each 'M' combination
assign Switch_H3 = ChangeSW[7:6];		//*****************

assign HEX0 = H0;		//============================================================================================
assign HEX1 = H1;		//
assign HEX2 = H2;		//The output HEX# takes the value of H# reg for each case, which is decoded for each SEL
assign HEX3 = H3;		//============================================================================================

//=======================================================
//  Structural coding
//=======================================================
always @(*)
begin
	case (Multiplexer)
		2'b00 : 
			begin 
				ChangeSW[1:0] = SW[1:0]; ChangeSW[3:2] = SW[3:2]; ChangeSW[5:4] = SW[5:4]; ChangeSW[7:6] = SW[7:6]; //Shows HELP
			end
		2'b01 : 
			begin
				ChangeSW[1:0] = SW[7:6]; ChangeSW[3:2] = SW[1:0]; ChangeSW[5:4] = SW[3:2]; ChangeSW[7:6] = SW[5:4]; //Shows ELPH
			end
		2'b10 : 
			begin 
				ChangeSW[1:0] = SW[5:4]; ChangeSW[3:2] = SW[7:6]; ChangeSW[5:4] = SW[1:0]; ChangeSW[7:6] = SW[3:2]; //Shows LPHE
			end
		2'b11 : 
			begin
				ChangeSW[1:0] = SW[3:2]; ChangeSW[3:2] = SW[5:4]; ChangeSW[5:4] = SW[7:6]; ChangeSW[7:6] = SW[1:0]; //Shows PHEL
			end
	endcase
	
	case (Switch_H0)			//Shows in HEX0 the corresponding character for the switch combination
		default : H0 = H;
		2'b01 : H0 = E;
		2'b10 : H0 = L;
		2'b11 : H0 = P;
	endcase 
	
	case (Switch_H1)		//Shows in HEX1 the corresponding character for the switch combination
		default : H1 = H;
		2'b01 : H1 = E;
		2'b10 : H1 = L;
		2'b11 : H1 = P;
	endcase 
	
	case (Switch_H2)		//Shows in HEX2 the corresponding character for the switch combination
		default : H2 = H;
		2'b01 : H2 = E;
		2'b10 : H2 = L;
		2'b11: H2 = P;
	endcase 
	
	case (Switch_H3)		//Shows in HEX3 the corresponding character for the switch combination
		default : H3 = H;
		2'b01 : H3 = E;
		2'b10 : H3 = L;
		2'b11 : H3 = P;
	endcase 
end
endmodule 