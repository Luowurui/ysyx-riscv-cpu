// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_cpu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop_cpu___024root.h"

VL_INLINE_OPT void Vtop_cpu___024root___ico_sequent__TOP__0(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top_cpu__DOT__rs1_data = vlSelf->top_cpu__DOT__gpr__DOT__registers
        [(0x1fU & (vlSelf->inst >> 0xfU))];
}

void Vtop_cpu___024root___eval_ico(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop_cpu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop_cpu___024root___eval_act(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_act\n"); );
}

void Vtop_cpu___024root___nba_sequent__TOP__0(Vtop_cpu___024root* vlSelf);

void Vtop_cpu___024root___eval_nba(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop_cpu___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop_cpu___024root___eval_triggers__ico(Vtop_cpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__ico(Vtop_cpu___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_cpu___024root___eval_triggers__act(Vtop_cpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__act(Vtop_cpu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_cpu___024root___dump_triggers__nba(Vtop_cpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_cpu___024root___eval(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop_cpu___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop_cpu___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top_cpu.v", 4, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop_cpu___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop_cpu___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop_cpu___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top_cpu.v", 4, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop_cpu___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop_cpu___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top_cpu.v", 4, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop_cpu___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop_cpu___024root___eval_debug_assertions(Vtop_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_cpu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
