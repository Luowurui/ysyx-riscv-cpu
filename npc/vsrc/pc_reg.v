module pc_reg (
    input clk,
    input rst_n,
    output reg [31:0] pc
);

    always @(posedge clk or negedge rst_n) begin
        if(!rst_n) 
            pc <= 32'h80000000;
        else
            pc <= pc + 32'd4;
    end
endmodule
