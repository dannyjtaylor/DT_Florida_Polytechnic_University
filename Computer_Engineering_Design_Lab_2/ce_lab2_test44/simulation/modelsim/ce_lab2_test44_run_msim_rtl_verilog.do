transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/ce_lab2_test44 {C:/Users/18639/Downloads/CodeGenerated/DE10_LITE/ce_lab2_test44/ce_lab2_test44.v}

