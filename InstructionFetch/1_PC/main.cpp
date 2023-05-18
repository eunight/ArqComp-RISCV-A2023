#include "PC.h"
#include "TestBench.h"

int sc_main(int argc, char* argv[]){
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);
	PC pc("pc");
	Testbench tb("tb");
	sc_signal<sc_int<32>> adressSg, adressAdderSg, adressPC_IF_IDSg, adressInstructionMemorySg;
	sc_signal<bool> HazardSg;
	
    tb.clk(clock);
	pc.clk(clock);
	pc.HazardIn(HazardSg);
	tb.HazardOut(HazardSg);
	pc.adressIn(adressSg);
	tb.adressOut(adressSg);
	pc.adressAdderOut(adressAdderSg);
	tb.adressAdderIn(adressAdderSg);
	pc.adressPC_IF_IDOut(adressPC_IF_IDSg);
	tb.adressPC_IF_IDIn(adressPC_IF_IDSg);
	pc.adressInstructionMemoryOut(adressInstructionMemorySg);
	tb.adressInstructionMemoryIn(adressInstructionMemorySg);
	sc_start();

	return 0;
}