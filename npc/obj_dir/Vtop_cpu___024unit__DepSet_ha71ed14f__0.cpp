// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_cpu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop_cpu__Syms.h"
#include "Vtop_cpu___024unit.h"

extern "C" void ebreak_handler();

VL_INLINE_OPT void Vtop_cpu___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_cpu___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit\n"); );
    // Body
    ebreak_handler();
}
