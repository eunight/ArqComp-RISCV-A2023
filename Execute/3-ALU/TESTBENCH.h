#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class TestBench : public sc_module {

public:

  sc_in<sc_int<32>> resultIn;
  sc_out<sc_int<32>>  Op1_Out, Op2_Out;
  sc_out<sc_int<5>>  instructOut;
  sc_in<bool> clk;

  SC_CTOR(TestBench);

private:

  void print();
  void process();
};

#endif
