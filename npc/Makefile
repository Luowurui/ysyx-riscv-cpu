all:
	@echo "Write this Makefile by your self."

sim:
	verilator --cc --exe --build -j 0 -Wall --trace sim_main.cpp top.v//生
	obj_dir/Vtop//打开文件
	gtkwave wave.vcd//打开波形
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."

include ../Makefile
