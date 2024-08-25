// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_cpu__Syms.h"


VL_ATTR_COLD void Vtop_cpu___024root__trace_init_sub__TOP__0(Vtop_cpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+35,"rst_n", false,-1);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->declBus(c+37,"inst", false,-1, 31,0);
    tracep->declBus(c+38,"mem_addr", false,-1, 31,0);
    tracep->declBus(c+39,"mem_data", false,-1, 31,0);
    tracep->declBit(c+40,"mem_write_enable", false,-1);
    tracep->pushNamePrefix("top_cpu ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+35,"rst_n", false,-1);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->declBus(c+37,"inst", false,-1, 31,0);
    tracep->declBus(c+38,"mem_addr", false,-1, 31,0);
    tracep->declBus(c+39,"mem_data", false,-1, 31,0);
    tracep->declBit(c+40,"mem_write_enable", false,-1);
    tracep->declBus(c+41,"rs1", false,-1, 4,0);
    tracep->declBus(c+42,"rs2", false,-1, 4,0);
    tracep->declBus(c+43,"rd", false,-1, 4,0);
    tracep->declBus(c+44,"opcode", false,-1, 6,0);
    tracep->declBus(c+45,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+46,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+47,"alu_result", false,-1, 31,0);
    tracep->declBus(c+48,"imm_value", false,-1, 31,0);
    tracep->declBit(c+49,"reg_write_enable", false,-1);
    tracep->pushNamePrefix("gpr ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+35,"rst_n", false,-1);
    tracep->declBus(c+41,"rs1", false,-1, 4,0);
    tracep->declBus(c+42,"rs2", false,-1, 4,0);
    tracep->declBus(c+43,"rd", false,-1, 4,0);
    tracep->declBus(c+47,"reg_write_data", false,-1, 31,0);
    tracep->declBit(c+49,"reg_write_enable", false,-1);
    tracep->declBus(c+45,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+46,"rs2_data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"registers", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+33,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+35,"rst_n", false,-1);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop_cpu___024root__trace_init_top(Vtop_cpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_init_top\n"); );
    // Body
    Vtop_cpu___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop_cpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_cpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_cpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop_cpu___024root__trace_register(Vtop_cpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop_cpu___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop_cpu___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop_cpu___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop_cpu___024root__trace_full_sub_0(Vtop_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop_cpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_full_top_0\n"); );
    // Init
    Vtop_cpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_cpu___024root*>(voidSelf);
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop_cpu___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop_cpu___024root__trace_full_sub_0(Vtop_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top_cpu__DOT__gpr__DOT__registers[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->top_cpu__DOT__gpr__DOT__registers[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->top_cpu__DOT__gpr__DOT__registers[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->top_cpu__DOT__gpr__DOT__registers[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->top_cpu__DOT__gpr__DOT__registers[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->top_cpu__DOT__gpr__DOT__registers[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->top_cpu__DOT__gpr__DOT__registers[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->top_cpu__DOT__gpr__DOT__registers[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->top_cpu__DOT__gpr__DOT__registers[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->top_cpu__DOT__gpr__DOT__registers[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->top_cpu__DOT__gpr__DOT__registers[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->top_cpu__DOT__gpr__DOT__registers[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->top_cpu__DOT__gpr__DOT__registers[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->top_cpu__DOT__gpr__DOT__registers[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->top_cpu__DOT__gpr__DOT__registers[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->top_cpu__DOT__gpr__DOT__registers[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->top_cpu__DOT__gpr__DOT__registers[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->top_cpu__DOT__gpr__DOT__registers[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->top_cpu__DOT__gpr__DOT__registers[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->top_cpu__DOT__gpr__DOT__registers[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->top_cpu__DOT__gpr__DOT__registers[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->top_cpu__DOT__gpr__DOT__registers[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->top_cpu__DOT__gpr__DOT__registers[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->top_cpu__DOT__gpr__DOT__registers[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->top_cpu__DOT__gpr__DOT__registers[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->top_cpu__DOT__gpr__DOT__registers[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->top_cpu__DOT__gpr__DOT__registers[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->top_cpu__DOT__gpr__DOT__registers[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->top_cpu__DOT__gpr__DOT__registers[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->top_cpu__DOT__gpr__DOT__registers[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->top_cpu__DOT__gpr__DOT__registers[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->top_cpu__DOT__gpr__DOT__registers[31]),32);
    bufp->fullIData(oldp+33,(vlSelf->top_cpu__DOT__gpr__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+34,(vlSelf->clk));
    bufp->fullBit(oldp+35,(vlSelf->rst_n));
    bufp->fullIData(oldp+36,(vlSelf->pc),32);
    bufp->fullIData(oldp+37,(vlSelf->inst),32);
    bufp->fullIData(oldp+38,(vlSelf->mem_addr),32);
    bufp->fullIData(oldp+39,(vlSelf->mem_data),32);
    bufp->fullBit(oldp+40,(vlSelf->mem_write_enable));
    bufp->fullCData(oldp+41,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+42,((0x1fU & (vlSelf->inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+43,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+44,((0x7fU & vlSelf->inst)),7);
    bufp->fullIData(oldp+45,(vlSelf->top_cpu__DOT__gpr__DOT__registers
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))]),32);
    bufp->fullIData(oldp+46,(vlSelf->top_cpu__DOT__gpr__DOT__registers
                             [(0x1fU & (vlSelf->inst 
                                        >> 0x14U))]),32);
    bufp->fullIData(oldp+47,((vlSelf->top_cpu__DOT__gpr__DOT__registers
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))] 
                              + (((- (IData)((vlSelf->inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->inst 
                                              >> 0x14U)))),32);
    bufp->fullIData(oldp+48,((((- (IData)((vlSelf->inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->inst 
                                           >> 0x14U))),32);
    bufp->fullBit(oldp+49,(1U));
}
