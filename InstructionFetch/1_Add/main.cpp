#include "Adder.h"
#include "TestBench.h"

int sc_main(int argc, char* argv[]){
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);

	Adder adder("adder");
	TestBench tb("tb");
	tb.clk(clock);

	sc_signal<sc_int<32>> aSg, resultSg;
	adder.aIn(aSg);
	tb.aOut(aSg);
	adder.resultOut(resultSg);
	tb.resultIn(resultSg);
	sc_start();
	return 0;
}