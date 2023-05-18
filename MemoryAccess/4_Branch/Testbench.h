#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:

  sc_out<bool> addressOut;
  sc_out<bool> jumpOut;
  sc_in<bool> clkIn, answerIn;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
