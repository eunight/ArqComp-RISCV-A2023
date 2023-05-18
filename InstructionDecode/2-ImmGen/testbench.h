#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

SC_MODULE(Testbench) {
  sc_out<sc_uint<32>> instruction;
  sc_in<sc_uint<32>> imm;

  void test();

  SC_CTOR(Testbench) {
    SC_THREAD(test);
  }
};

#endif