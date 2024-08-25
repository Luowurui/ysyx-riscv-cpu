// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP_CPU__SYMS_H_
#define VERILATED_VTOP_CPU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop_cpu.h"

// INCLUDE MODULE CLASSES
#include "Vtop_cpu___024root.h"

// SYMS CLASS (contains all model state)
class Vtop_cpu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop_cpu* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop_cpu___024root             TOP;

    // CONSTRUCTORS
    Vtop_cpu__Syms(VerilatedContext* contextp, const char* namep, Vtop_cpu* modelp);
    ~Vtop_cpu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
