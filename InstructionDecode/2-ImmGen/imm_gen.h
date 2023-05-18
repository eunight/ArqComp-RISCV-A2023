#ifndef IMM_GEN_H
#define IMM_GEN_H

#include <systemc.h>

SC_MODULE(ImmGen) {
  sc_in<sc_uint<32>> instruction;
  sc_out<sc_uint<32>> imm;

  void generate_imm();

  SC_CTOR(ImmGen) {
    SC_METHOD(generate_imm);
    sensitive << instruction;
  }
};

#endif