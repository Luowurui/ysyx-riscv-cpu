// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_cpu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop_cpu__Syms.h"
#include "Vtop_cpu___024unit.h"

void Vtop_cpu___024unit___ctor_var_reset(Vtop_cpu___024unit* vlSelf);

Vtop_cpu___024unit::Vtop_cpu___024unit(Vtop_cpu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_cpu___024unit___ctor_var_reset(this);
}

void Vtop_cpu___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_cpu___024unit::~Vtop_cpu___024unit() {
}
