#ifndef REGISTERS_H
#define REGISTERS_H

#include <systemc.h>

SC_MODULE(Registers) {
  sc_in_clk clk;
  sc_in<sc_uint<5>> rd1, rd2;
  sc_in<sc_uint<5>> wd;
  sc_in<sc_logic> wen;
  sc_out<sc_uint<32>> data1, data2;

  sc_uint<32> regs[32];

  void read_registers();
  void write_registers();

  SC_CTOR(Registers) {
    SC_METHOD(read_registers);
    sensitive << rd1 << rd2;

    SC_METHOD(write_registers);
    sensitive << clk.pos();
  }
};

#endif // REGISTERS_H