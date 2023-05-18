#ifndef MUX_H
#define MUX_H

#include <systemc.h>

class mux: public sc_module{
public:
	sc_in<bool> aIn, bIn;
	sc_in<sc_int<32>> Op1_In, Op2_In, Op3_In;
	sc_out<sc_int<32>> Op_Out;

	SC_CTOR(Mux);
  
private:
	void process();
};

#endif
