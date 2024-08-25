// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_cpu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop_cpu___024root.h"

VL_ATTR_COLD void Vtop_cpu___024root___eval_static(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop_cpu___024root___eval_initial__TOP(Vtop_cpu___024root* vlSelf);

VL_ATTR_COLD void Vtop_cpu___024root___eval_initial(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_initial\n"); );
    // Body
    Vtop_cpu___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst_n = vlSelf->rst_n;
}

VL_ATTR_COLD void Vtop_cpu___024root___eval_initial__TOP(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->mem_write_enable = 0U;
    vlSelf->mem_addr = 0U;
    vlSelf->mem_data = 0U;
}

VL_ATTR_COLD void Vtop_cpu___024root___eval_final(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop_cpu___024root___eval_triggers__stl(Vtop_cpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__stl(Vtop_cpu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___eval_stl(Vtop_cpu___024root* vlSelf);

VL_ATTR_COLD void Vtop_cpu___024root___eval_settle(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop_cpu___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop_cpu___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top_cpu.v", 4, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop_cpu___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__stl(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop_cpu___024root___ico_sequent__TOP__0(Vtop_cpu___024root* vlSelf);

VL_ATTR_COLD void Vtop_cpu___024root___eval_stl(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop_cpu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__ico(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__act(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__nba(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_cpu___024root___ctor_var_reset(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->mem_addr = VL_RAND_RESET_I(32);
    vlSelf->mem_data = VL_RAND_RESET_I(32);
    vlSelf->mem_write_enable = VL_RAND_RESET_I(1);
    vlSelf->top_cpu__DOT__rs1_data = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top_cpu__DOT__gpr__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top_cpu__DOT__gpr__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst_n = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
