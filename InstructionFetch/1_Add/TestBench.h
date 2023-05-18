#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <iostream>
#include <systemc.h>

class TestBench : public sc_module{    
    public:
	    sc_in_clk clk;
	    sc_out<sc_int<32>> aOut;
	    sc_in<sc_int<32>> resultIn;
	    SC_CTOR(TestBench);
    private:
	    void print();
	    void test();
};
#endif