transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter {C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter/my_counter.v}
vlog -vlog01compat -work work +incdir+C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter {C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter/SEG7_LUT.v}
vlog -vlog01compat -work work +incdir+C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter {C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter/ce_lab2_counter.v}

vlog -vlog01compat -work work +incdir+C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter {C:/Users/onur/Desktop/MyWork/Quartus/CodeGenerated/DE10_LITE/CE_Lab2_Counter/my_testbench.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L fiftyfivenm_ver -L rtl_work -L work -voptargs="+acc"  my_testbench

add wave *
view structure
view signals
run -all
