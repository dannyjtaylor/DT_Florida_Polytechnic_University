transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/18639/Downloads/CodeGenerated/DE10_LITE {C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/shiftandarithmeticFPGA.v}
vlog -vlog01compat -work work +incdir+C:/Users/18639/Downloads/CodeGenerated/DE10_LITE {C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/addandmultiply.v}
vlog -vlog01compat -work work +incdir+C:/Users/18639/Downloads/CodeGenerated/DE10_LITE {C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/shiftandarithmetic_SegmentConversion.v}

vlog -vlog01compat -work work +incdir+C:/Users/18639/Downloads/CodeGenerated/DE10_LITE {C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/shiftandarithmeticTestbench.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L fiftyfivenm_ver -L rtl_work -L work -voptargs="+acc"  saa_tb

add wave *
view structure
view signals
run -all
