#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

SC_MODULE(Testbench) {
  sc_in_clk clk;
  sc_out<sc_uint<5>> rd1, rd2, wd;
  sc_out<sc_logic> wen;
  sc_in<sc_uint<32>> data1, data2;

  void monitor();

  SC_CTOR(Testbench) {
    SC_THREAD(monitor);
    sensitive << clk.pos();
  }
};

#endif // TESTBENCH_H