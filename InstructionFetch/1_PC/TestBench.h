#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <iostream>
#include <systemc.h>

class Testbench : public sc_module {
    public:
	    sc_in_clk clk;
    	sc_out<bool> HazardOut;
    	sc_out<sc_int<32>> adressOut;
    	sc_in<sc_int<32>>adressAdderIn, adressPC_IF_IDIn, adressInstructionMemoryIn;
    	SC_CTOR(Testbench);

    private:
	    void test();
	    void print();
};
#endif