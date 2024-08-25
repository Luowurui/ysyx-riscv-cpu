// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_cpu__Syms.h"


void Vtop_cpu___024root__trace_chg_sub_0(Vtop_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_cpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_chg_top_0\n"); );
    // Init
    Vtop_cpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_cpu___024root*>(voidSelf);
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop_cpu___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop_cpu___024root__trace_chg_sub_0(Vtop_cpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top_cpu__DOT__gpr__DOT__registers[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->top_cpu__DOT__gpr__DOT__registers[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->top_cpu__DOT__gpr__DOT__registers[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->top_cpu__DOT__gpr__DOT__registers[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->top_cpu__DOT__gpr__DOT__registers[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->top_cpu__DOT__gpr__DOT__registers[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->top_cpu__DOT__gpr__DOT__registers[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->top_cpu__DOT__gpr__DOT__registers[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->top_cpu__DOT__gpr__DOT__registers[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->top_cpu__DOT__gpr__DOT__registers[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->top_cpu__DOT__gpr__DOT__registers[10]),32);
        bufp->chgIData(oldp+11,(vlSelf->top_cpu__DOT__gpr__DOT__registers[11]),32);
        bufp->chgIData(oldp+12,(vlSelf->top_cpu__DOT__gpr__DOT__registers[12]),32);
        bufp->chgIData(oldp+13,(vlSelf->top_cpu__DOT__gpr__DOT__registers[13]),32);
        bufp->chgIData(oldp+14,(vlSelf->top_cpu__DOT__gpr__DOT__registers[14]),32);
        bufp->chgIData(oldp+15,(vlSelf->top_cpu__DOT__gpr__DOT__registers[15]),32);
        bufp->chgIData(oldp+16,(vlSelf->top_cpu__DOT__gpr__DOT__registers[16]),32);
        bufp->chgIData(oldp+17,(vlSelf->top_cpu__DOT__gpr__DOT__registers[17]),32);
        bufp->chgIData(oldp+18,(vlSelf->top_cpu__DOT__gpr__DOT__registers[18]),32);
        bufp->chgIData(oldp+19,(vlSelf->top_cpu__DOT__gpr__DOT__registers[19]),32);
        bufp->chgIData(oldp+20,(vlSelf->top_cpu__DOT__gpr__DOT__registers[20]),32);
        bufp->chgIData(oldp+21,(vlSelf->top_cpu__DOT__gpr__DOT__registers[21]),32);
        bufp->chgIData(oldp+22,(vlSelf->top_cpu__DOT__gpr__DOT__registers[22]),32);
        bufp->chgIData(oldp+23,(vlSelf->top_cpu__DOT__gpr__DOT__registers[23]),32);
        bufp->chgIData(oldp+24,(vlSelf->top_cpu__DOT__gpr__DOT__registers[24]),32);
        bufp->chgIData(oldp+25,(vlSelf->top_cpu__DOT__gpr__DOT__registers[25]),32);
        bufp->chgIData(oldp+26,(vlSelf->top_cpu__DOT__gpr__DOT__registers[26]),32);
        bufp->chgIData(oldp+27,(vlSelf->top_cpu__DOT__gpr__DOT__registers[27]),32);
        bufp->chgIData(oldp+28,(vlSelf->top_cpu__DOT__gpr__DOT__registers[28]),32);
        bufp->chgIData(oldp+29,(vlSelf->top_cpu__DOT__gpr__DOT__registers[29]),32);
        bufp->chgIData(oldp+30,(vlSelf->top_cpu__DOT__gpr__DOT__registers[30]),32);
        bufp->chgIData(oldp+31,(vlSelf->top_cpu__DOT__gpr__DOT__registers[31]),32);
        bufp->chgIData(oldp+32,(vlSelf->top_cpu__DOT__gpr__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+33,(vlSelf->clk));
    bufp->chgBit(oldp+34,(vlSelf->rst_n));
    bufp->chgIData(oldp+35,(vlSelf->pc),32);
    bufp->chgIData(oldp+36,(vlSelf->inst),32);
    bufp->chgIData(oldp+37,(vlSelf->mem_addr),32);
    bufp->chgIData(oldp+38,(vlSelf->mem_data),32);
    bufp->chgBit(oldp+39,(vlSelf->mem_write_enable));
    bufp->chgCData(oldp+40,((0x1fU & (vlSelf->inst 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+41,((0x1fU & (vlSelf->inst 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+42,((0x1fU & (vlSelf->inst 
                                      >> 7U))),5);
    bufp->chgCData(oldp+43,((0x7fU & vlSelf->inst)),7);
    bufp->chgIData(oldp+44,(vlSelf->top_cpu__DOT__gpr__DOT__registers
                            [(0x1fU & (vlSelf->inst 
                                       >> 0xfU))]),32);
    bufp->chgIData(oldp+45,(vlSelf->top_cpu__DOT__gpr__DOT__registers
                            [(0x1fU & (vlSelf->inst 
                                       >> 0x14U))]),32);
    bufp->chgIData(oldp+46,((vlSelf->top_cpu__DOT__gpr__DOT__registers
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))] 
                             + (((- (IData)((vlSelf->inst 
                                             >> 0x1fU))) 
                                 << 0xcU) | (vlSelf->inst 
                                             >> 0x14U)))),32);
    bufp->chgIData(oldp+47,((((- (IData)((vlSelf->inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelf->inst 
                                          >> 0x14U))),32);
}

void Vtop_cpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root__trace_cleanup\n"); );
    // Init
    Vtop_cpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_cpu___024root*>(voidSelf);
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
