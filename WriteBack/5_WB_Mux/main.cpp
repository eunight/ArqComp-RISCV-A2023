#include "5_WB_Mux.h"
#include "Testbench.h"

int sc_main(int argc, char* argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);

	Mux mux("mux");
	Testbench tb("tb");

	tb.clk(clock);

	sc_signal<bool> sSg;
	sc_signal<sc_int<32>> aSg, bSg;
	sc_signal<sc_int<32>> cSg;

	mux.sIn(sSg);
	tb.sOut(sSg);

	mux.aIn(aSg);
	tb.aOut(aSg);

	mux.bIn(bSg);
	tb.bOut(bSg);

	mux.cOut(cSg);
	tb.cIn(cSg);

	sc_start();

	return 0;
}