#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <iostream>
#include <systemc.h>

class Testbench : public sc_module{
public:
	sc_in_clk clk;
	sc_out<bool> sOut;
	sc_out<sc_int<32>> aOut, bOut;
	sc_in<sc_int<32>> cIn;
	SC_CTOR(Testbench);
    
private:
	void print();
	void test();
};

#endif