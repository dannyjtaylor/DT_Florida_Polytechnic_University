# Copyright (C) 2022  Intel Corporation. All rights reserved.
# Your use of Intel Corporation's design tools, logic functions 
# and other software and tools, and any partner logic 
# functions, and any output files from any of the foregoing 
# (including device programming or simulation files), and any 
# associated documentation or information are expressly subject 
# to the terms and conditions of the Intel Program License 
# Subscription Agreement, the Intel Quartus Prime License Agreement,
# the Intel FPGA IP License Agreement, or other applicable license
# agreement, including, without limitation, that your use is for
# the sole purpose of programming logic devices manufactured by
# Intel and sold by Intel or its authorized distributors.  Please
# refer to the applicable agreement for further details, at
# https://fpgasoftware.intel.com/eula.


# ***************************************************************************
# ***************************************************************************
# 
# File:		C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/simulation/modelsim/ShiftAndCombine_dump_all_vcd_nodes.tcl
# 
# Description:	Script for Questa Intel FPGA (Verilog) VCD File Dumping
# 		This script is used to direct Questa Intel FPGA (Verilog) to dump
# 		all nodes in the design to a VCD output file
# 
# Usages:	C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/simulation/modelsim/ShiftAndCombine_dump_all_vcd_nodes.tcl
# 
# Generated by:	Quartus Prime
# 		Version 21.1.1 Build 850 06/23/2022 SJ Lite Edition
# 
# Date:		Mon Feb  3 15:37:43 2025
# 
# Design:	ShiftAndCombine
# 
# ***************************************************************************
# ***************************************************************************

# ----------------------------------------------------------------
#
proc add_vcd_signals { hierarchy vcd_filename } {
#
# Description:	This function directs Questa Intel FPGA (Verilog) to print out the
#		appropriate VCD signals, with the hierarchy level
#		prepended to each signal name
#
# ----------------------------------------------------------------

   catch { vcd add "$hierarchy/a1_asum_a0_a_a0_combout" }
   catch { vcd add "$hierarchy/a1_asum_a0_a_a1" }
   catch { vcd add "$hierarchy/a1_asum_a1_a_a2_combout" }
   catch { vcd add "$hierarchy/a1_asum_a1_a_a3" }
   catch { vcd add "$hierarchy/a1_asum_a2_a_a4_combout" }
   catch { vcd add "$hierarchy/a1_asum_a2_a_a5" }
   catch { vcd add "$hierarchy/a1_asum_a3_a_a6_combout" }
   catch { vcd add "$hierarchy/a1_asum_a3_a_a7" }
   catch { vcd add "$hierarchy/a1_acarryout_a0_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a0_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a1" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a2_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a3" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a0_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a1" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a4_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a5" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a2_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a3" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a6_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a7" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a4_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a5" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a8_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a9" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a6_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a7" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a10_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a11" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a8_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a9" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a12_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a13" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_1_a10_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_aop_3_a14_combout" }
   catch { vcd add "$hierarchy/dispCombine2_aDecoder0_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine2_aWideOr5_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine2_aWideOr4_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine2_aWideOr3_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine2_aDecoder0_a1_combout" }
   catch { vcd add "$hierarchy/dispCombine2_aWideOr0_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine_aWideOr6_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine_aWideOr5_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine_aWideOr4_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine_aWideOr3_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine_aWideOr2_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine_aWideOr1_a0_combout" }
   catch { vcd add "$hierarchy/dispCombine_aWideOr0_a0_combout" }
   catch { vcd add "$hierarchy/dispAdd_aWideOr6_a0_combout" }
   catch { vcd add "$hierarchy/dispAdd_aWideOr5_a0_combout" }
   catch { vcd add "$hierarchy/dispAdd_aWideOr4_a0_combout" }
   catch { vcd add "$hierarchy/dispAdd_aWideOr3_a0_combout" }
   catch { vcd add "$hierarchy/dispAdd_aWideOr2_a0_combout" }
   catch { vcd add "$hierarchy/dispAdd_aWideOr1_a0_combout" }
   catch { vcd add "$hierarchy/dispAdd_aWideOr0_a0_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale4a\[5\]" }
   catch { vcd add "$hierarchy/dispProduct1_aWideOr6_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct1_aWideOr5_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct1_aWideOr4_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct1_aWideOr3_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct1_aWideOr2_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct1_aWideOr1_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct1_aWideOr0_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct2_aWideOr6_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct2_aWideOr5_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct2_aWideOr4_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct2_aWideOr3_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct2_aWideOr2_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct2_aWideOr1_a0_combout" }
   catch { vcd add "$hierarchy/dispProduct2_aWideOr0_a0_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale3a\[0\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale3a\[1\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale3a\[2\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale4a\[0\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale3a\[3\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_acs2a_a1_a_a0_combout" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale4a\[1\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale3a\[4\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale4a\[2\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale5a\[0\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale4a\[3\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale5a\[1\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale4a\[4\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale5a\[2\]" }
   catch { vcd add "$hierarchy/m1_aMult0_aauto_generated_ale5a\[3\]" }
   catch { vcd add "$hierarchy/HEX0_a0_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX0_a1_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX0_a2_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX0_a3_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX0_a4_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX0_a5_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX0_a6_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX0_a7_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a0_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a1_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a2_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a3_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a4_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a5_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a6_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX1_a7_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a0_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a1_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a2_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a3_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a4_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a5_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a6_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX2_a7_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a0_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a1_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a2_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a3_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a4_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a5_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a6_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX3_a7_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a0_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a1_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a2_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a3_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a4_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a5_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a6_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX4_a7_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a0_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a1_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a2_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a3_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a4_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a5_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a6_a_aoutput_o" }
   catch { vcd add "$hierarchy/HEX5_a7_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a0_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a1_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a2_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a3_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a4_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a5_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a6_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a7_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a8_a_aoutput_o" }
   catch { vcd add "$hierarchy/LEDR_a9_a_aoutput_o" }
   catch { vcd add "$hierarchy/SW_a1_a_ainput_o" }
   catch { vcd add "$hierarchy/SW_a0_a_ainput_o" }
   catch { vcd add "$hierarchy/SW_a2_a_ainput_o" }
   catch { vcd add "$hierarchy/SW_a3_a_ainput_o" }
   catch { vcd add "$hierarchy/SW_a4_a_ainput_o" }
   catch { vcd add "$hierarchy/SW_a5_a_ainput_o" }
   catch { vcd add "$hierarchy/SW_a6_a_ainput_o" }
   catch { vcd add "$hierarchy/SW_a7_a_ainput_o" }
   catch { vcd add "$hierarchy/a_aQUARTUS_CREATED_GND_aI_combout" }
}

# ----------------------------------------------------------------
#
proc main { argv } {
#
# Description:	Main entry point to script.  Iterate over all
#		hierarchy levels specified, and direct Questa Intel FPGA (Verilog)
#		to print the relevant signals under each level
#
# ----------------------------------------------------------------

   set vcd_filename "ShiftAndCombine.vcd"
   set hierarchy "uut"

   vcd file "$vcd_filename"
   vcd on

   add_vcd_signals $hierarchy $vcd_filename
}

main $argv
