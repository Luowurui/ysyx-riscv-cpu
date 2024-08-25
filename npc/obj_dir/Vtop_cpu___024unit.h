// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_cpu.h for the primary calling header

#ifndef VERILATED_VTOP_CPU___024UNIT_H_
#define VERILATED_VTOP_CPU___024UNIT_H_  // guard

#include "verilated.h"

class Vtop_cpu__Syms;

class Vtop_cpu___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtop_cpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_cpu___024unit(Vtop_cpu__Syms* symsp, const char* v__name);
    ~Vtop_cpu___024unit();
    VL_UNCOPYABLE(Vtop_cpu___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
