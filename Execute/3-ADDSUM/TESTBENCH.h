#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class TestBench : public sc_module {
    public:
    
    	sc_in_clk clk;
    	
    	sc_out<sc_int<32>> aOut, bOut;
    	sc_in<sc_int<32>> resultIn;
    	
    	SC_CTOR(TestBench);

    private:
	    void print();
	    void test();
};

#endif //TESTBENCH_H
