import "DPI-C" function void ebreak_handler();


module top_cpu (
    input  clk,               // 时钟信号
    input  rst_n,               // 复位信号
    output  [31:0] pc,        // 当前指令地址 (连接到外部存储器)
    input  [31:0] inst,       // 外部存储器返回的指令
    output  [31:0] mem_addr,  // 存储器地址 (用于数据访问)
    output  [31:0] mem_data,  // 要写入存储器的数据
    output  mem_write_enable  // 存储器写使能
);

    // 内部信号
    wire [4:0] rs1, rs2, rd;
    wire [6:0] opcode;
    wire [31:0] rs1_data, rs2_data, alu_result,imm_value;
    wire reg_write_enable;

    // 实例化PC寄存器
    pc_reg pc_reg (
        .clk(clk),
        .rst_n(rst_n),
        .pc(pc)
    );

    // 实例化IFU (取指单元)
    assign rs1 = inst[19:15];    // 操作数1的寄存器地址
    assign rs2 = inst[24:20];    // 操作数2的寄存器地址
    assign rd  = inst[11:7];     // 目标寄存器地址
    assign imm_value = {{20{inst[31]}}, inst[31:20]};  // 立即数扩展
    assign opcode =inst[6:0];

    // 实例化寄存器文件
    gpr gpr (
        .clk(clk),
        .rst_n(rst_n),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .reg_write_data(alu_result),
        .reg_write_enable(reg_write_enable),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data)
    );

    always @(posedge clk or negedge rst_n) begin

            if (inst == 32'h00100073) begin  // Assuming ebreak is 32'h00100073
                ebreak_handler();  // Call the C function to end simulation
            end
            
    end


    // // 实例化ALU (执行单元)
    // alu alu_inst (
    //     .operand1(rs1_data),
    //     .operand2(rs2_data),
    //     .result(alu_result)
    // );

    // 实例化ALU
    assign alu_result = rs1_data + imm_value;

    // 写回阶段：将ALU的结果写回寄存器
    assign reg_write_enable = 1'b1;  // 假设始终写回结果

    // 假设此处没有对存储器的写操作
    assign mem_write_enable = 1'b0;
    assign mem_addr = 32'b0;
    assign mem_data = 32'b0;

endmodule
