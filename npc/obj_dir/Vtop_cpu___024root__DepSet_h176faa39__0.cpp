// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_cpu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop_cpu__Syms.h"
#include "Vtop_cpu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__ico(Vtop_cpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_cpu___024root___eval_triggers__ico(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_cpu___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__act(Vtop_cpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_cpu___024root___eval_triggers__act(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((~ (IData)(vlSelf->rst_n)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__rst_n)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst_n = vlSelf->rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_cpu___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop_cpu___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit();

VL_INLINE_OPT void Vtop_cpu___024root___nba_sequent__TOP__0(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top_cpu__DOT__gpr__DOT__registers__v0;
    __Vdlyvdim0__top_cpu__DOT__gpr__DOT__registers__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top_cpu__DOT__gpr__DOT__registers__v0;
    __Vdlyvval__top_cpu__DOT__gpr__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v0;
    __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v1;
    __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v1 = 0;
    // Body
    if ((0x100073U == vlSelf->inst)) {
        Vtop_cpu___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit();
    }
    __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v0 = 0U;
    __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v1 = 0U;
    if ((1U & (~ (IData)(vlSelf->rst_n)))) {
        vlSelf->top_cpu__DOT__gpr__DOT__unnamedblk1__DOT__i = 0x20U;
    }
    if (vlSelf->rst_n) {
        vlSelf->pc = ((IData)(4U) + vlSelf->pc);
        if ((0U != (0x1fU & (vlSelf->inst >> 7U)))) {
            __Vdlyvval__top_cpu__DOT__gpr__DOT__registers__v0 
                = (vlSelf->top_cpu__DOT__rs1_data + 
                   (((- (IData)((vlSelf->inst >> 0x1fU))) 
                     << 0xcU) | (vlSelf->inst >> 0x14U)));
            __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v0 = 1U;
            __Vdlyvdim0__top_cpu__DOT__gpr__DOT__registers__v0 
                = (0x1fU & (vlSelf->inst >> 7U));
        }
    } else {
        vlSelf->pc = 0x80000000U;
        __Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v1 = 1U;
    }
    if (__Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v0) {
        vlSelf->top_cpu__DOT__gpr__DOT__registers[__Vdlyvdim0__top_cpu__DOT__gpr__DOT__registers__v0] 
            = __Vdlyvval__top_cpu__DOT__gpr__DOT__registers__v0;
    }
    if (__Vdlyvset__top_cpu__DOT__gpr__DOT__registers__v1) {
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[1U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[2U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[3U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[4U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[5U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[6U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[7U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[8U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[9U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0xaU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0xbU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0xcU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0xdU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0xeU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0xfU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x10U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x11U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x12U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x13U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x14U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x15U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x16U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x17U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x18U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x19U] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x1aU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x1bU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x1cU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x1dU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x1eU] = 0U;
        vlSelf->top_cpu__DOT__gpr__DOT__registers[0x1fU] = 0U;
    }
    vlSelf->top_cpu__DOT__rs1_data = vlSelf->top_cpu__DOT__gpr__DOT__registers
        [(0x1fU & (vlSelf->inst >> 0xfU))];
}
