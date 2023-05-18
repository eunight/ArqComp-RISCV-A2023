#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

SC_MODULE(Testbench)
{
    sc_out<sc_bv<32>> instruction;
    sc_out<sc_bv<5>> rs1;
    sc_out<sc_bv<5>> rs2;
    sc_out<sc_bv<5>> rd;
    sc_in<sc_bv<32>> imm;

    void generateInstruction();

    SC_CTOR(Testbench)
    {
        SC_THREAD(generateInstruction);
    }
};

#endif