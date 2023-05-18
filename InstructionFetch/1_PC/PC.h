#ifndef PC_H
#define PC_H
#include <systemc.h>

class PC : public sc_module {

	public:
		sc_in_clk clk;
		sc_in<sc_int<32>> adressIn;
		sc_in<bool> HazardIn;
		sc_out<sc_int<32>> adressAdderOut;
		sc_out<sc_int<32>> adressPC_IF_IDOut;
		sc_out<sc_int<32>> adressInstructionMemoryOut;
		SC_CTOR(PC);

	private:
		sc_int<32> adress;
		void read();
		void write();
};
#endif