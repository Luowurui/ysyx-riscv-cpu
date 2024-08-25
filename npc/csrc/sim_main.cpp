// For std::unique_ptr
#include <memory>

#include "Vtop_cpu.h"
#include "verilated.h"

#include "verilated_vcd_c.h"

#include <stdio.h>
#include <stdlib.h>
#include "svdpi.h"
#include "Vtop_cpu__Dpi.h"

// C function to be called from Verilog
void ebreak_handler() {
    printf("Ebreak instruction executed. Ending simulation.\n");
    // You can use `exit()` to terminate the simulation
    exit(0);
}


uint32_t pmem_read(uint32_t addr) {
    // 示例指令：addi x1, x0, 10; addi x2, x0, 20; addi x3, x1, 5;
    // 这段内存中包含三条指令，分别向x1, x2, x3寄存器写入值
    switch(addr) {
        case 0x80000000: return 0x00000513; // addi x10, x0, 10 (x1 = 0 + 10)
        case 0x80000004: return 0x00000A13; // addi x10, x0, 20 (x2 = 0 + 20)
        case 0x80000008: return 0x00028593; // addi x11, x5, 5 (x3 = x1 + 5)
        case 0x8000000C: return 0x00100073; // ebreak
        default: return 0;
    }
}

int main(int argc, char **argv, char **env) {

    // 创建顶层模块实例，并传递仿真上下文
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    const std::unique_ptr<Vtop_cpu> top{new Vtop_cpu{contextp.get(), "TOP"}};
    

    contextp->traceEverOn(true);  
    VerilatedVcdC* tfp = new VerilatedVcdC;

    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    contextp->commandArgs(argc, argv);


    top->trace(tfp, 99);  // Trace 99 levels of hierarchy
    
    tfp->open("wsrc/wave.vcd");  // 打开 VCD 文件

    // 创建仿真上下文


    // 启用 VCD 波形跟踪

    top->rst_n = 0;  // 初始化复位
    top->clk = 0;
   
    // 仿真主循环
    while (contextp->time()<100) {  // 模拟100个时钟周期

        contextp->timeInc(1);

        top->clk = !top->clk;
        top->inst = pmem_read(top->pc);  // 根据PC读取指令
        top->eval();  // 计算下一个时钟周期

        if (!top->clk) {
            if ( contextp->time() < 10) {
                top->rst_n = 0;  // Assert reset
            } else {
                top->rst_n = 1;  // Deassert reset
            }
        }
        if (contextp->time() % 2 == 1) {
            printf("PC: %08x | Instruction: %08x\n", top->pc, top->inst);
        }



        top->eval();  // 计算下一个时钟周期
        tfp->dump(contextp->time());
    }
    tfp->close();
    exit(0);
}
