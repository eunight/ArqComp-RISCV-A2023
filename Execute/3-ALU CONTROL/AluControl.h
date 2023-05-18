#ifndef AluControl_H
#define AluControl_H

#include <systemc.h>

class AluContrl : public sc_module
{
public:
	sc_in_clk clkIn;

    sc_in<bool> Mem_MemWriteIn, Mem_MemReadIn;
    sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn;
    sc_in<sc_uint<5>> Ex_ALUIn;

    sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut;
    sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut;
    sc_out<sc_uint<5>> Ex_ALUOut;


    sc_in<sc_int<32>> rs1In, rs2In, imm_genIn;
    sc_in<sc_uint<5>> rs1_registerIn, rs2_registerIn, target_registerIn;

    sc_out<sc_int<32>> rs1Out, rs2Out;
    sc_out<sc_uint<5>> rs1_registerOut, rs2_registerOut, target_registerOut;
    

	SC_CTOR(id_ex);

private:
	void process();
};

#endif
