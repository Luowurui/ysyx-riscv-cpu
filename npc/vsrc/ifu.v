module ifu (
    input clk,
    input rst_n,
    input [31:0] pc,
    output reg [31:0] inst
);

    pc_reg pc_reg (.clk(clk),.rst_n(rst_n),.pc(pc));
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            inst <= 32'b0;
        end
        else begin
            inst <= mem_read(pc);
        end
    end

endmodule
