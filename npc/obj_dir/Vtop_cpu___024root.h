// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_cpu.h for the primary calling header

#ifndef VERILATED_VTOP_CPU___024ROOT_H_
#define VERILATED_VTOP_CPU___024ROOT_H_  // guard

#include "verilated.h"

class Vtop_cpu__Syms;
class Vtop_cpu___024unit;


class Vtop_cpu___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_cpu___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(mem_write_enable,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst_n;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc,31,0);
    VL_IN(inst,31,0);
    VL_OUT(mem_addr,31,0);
    VL_OUT(mem_data,31,0);
    IData/*31:0*/ top_cpu__DOT__rs1_data;
    IData/*31:0*/ top_cpu__DOT__gpr__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top_cpu__DOT__gpr__DOT__registers;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop_cpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_cpu___024root(Vtop_cpu__Syms* symsp, const char* v__name);
    ~Vtop_cpu___024root();
    VL_UNCOPYABLE(Vtop_cpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
