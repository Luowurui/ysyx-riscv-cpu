module gpr (
    input wire clk,
    input wire rst_n,
    input wire [4:0] rs1,          // 读寄存器1地址
    input wire [4:0] rs2,          // 读寄存器2地址
    input wire [4:0] rd,           // 写寄存器地址
    input wire [31:0] reg_write_data,  // 要写入的数据
    input wire reg_write_enable,   // 写使能信号
    output reg [31:0] rs1_data,    // 读寄存器1数据
    output reg [31:0] rs2_data     // 读寄存器2数据
);
    // 32个32位寄存器
    reg [31:0] registers [31:0];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // 初始化所有寄存器为0
            integer i;
            for (i = 0; i < 32; i = i + 1)
                registers[i] <= 32'b0;
        end else begin
            if (reg_write_enable && rd != 5'b00000) // 寄存器0保持为0
                registers[rd] <= reg_write_data;
        end
    end

    always @(*) begin
        rs1_data = registers[rs1];
        rs2_data = registers[rs2];
    end
    
endmodule
