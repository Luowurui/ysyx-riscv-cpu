module exu (
    input wire [31:0] src1,
    input wire [31:0] src2,
    input wire [31:0] imm,
    input wire [6:0] opcode,
    input wire [2:0] funct3,
    input wire [6:0] funct7,
    output reg [31:0] result
);
    always @(*) begin
        case (opcode)
            7'b0010011: begin // ADDI
                result = src1 + imm;
            end
            default: result = 32'b0;
        endcase
    end
endmodule
