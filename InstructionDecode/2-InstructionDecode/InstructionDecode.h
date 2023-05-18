#ifndef INSTRUCTION_DECODE_H
#define INSTRUCTION_DECODE_H

#include <systemc.h>

SC_MODULE(InstructionDecode)
{
    sc_in<sc_bv<32>> instruction;
    sc_in<sc_bv<5>> rs1;
    sc_in<sc_bv<5>> rs2;
    sc_in<sc_bv<5>> rd;
    sc_out<sc_bv<32>> imm;

    void decodeInstruction();

    SC_CTOR(InstructionDecode)
    {
        SC_METHOD(decodeInstruction);
        sensitive << instruction;
    }
};

#endif