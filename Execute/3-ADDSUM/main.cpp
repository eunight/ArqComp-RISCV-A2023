#include "AddSum.h"
#include "TESTBENCH.h"

int sc_main(int argc, char* argv[]){

	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);

	AddSUM addsum("addsum");
	TestBench tb("tb");

	tb.clk(clock);

	sc_signal<sc_int<32>> aSg, bSg, resultSg;

	addsum.aIn(aSg);
	tb.aOut(aSg);

	addsum.bIn(bSg);
	tb.bOut(bSg);

	addsum.resultOut(resultSg);
	tb.resultIn(resultSg);

	sc_start();

	return 0;
}
