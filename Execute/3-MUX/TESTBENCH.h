#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class TestBench : public sc_module {
  public:
    
    
	sc_in<bool> clkIn;
	sc_in<sc_int<32>> Op_In;
	sc_out<sc_int<32>> Op1_Out, Op2_Out;
	sc_out<bool> aOut, bOut;

  	SC_CTOR(TestBench);

  private:
	  void print();
	  void test();
};

#endif // TESTBENCH_H
