#ifndef EX_MEM_H
#define EX_MEM_H

#include <systemc.h>

class EX_MEM : public sc_module
{
public:
	sc_in_clk clkIn;
	sc_in<bool> alu_to_brachIn;
	sc_out<bool> alu_to_brachOut;

	sc_in<bool> Mem_MemWriteIn, Mem_MemReadIn, Mem_BranchIn;
	sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn;

	sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut; 

	sc_in<sc_int<32>> memo_In[3];
	sc_out<sc_int<32>> memo_Out[4];

	sc_in<sc_uint<5>> dir_In;
	sc_out<sc_uint<5>> dir_Out;

	SC_CTOR(EX_MEM);

private:
	void operation();
};

#endif
