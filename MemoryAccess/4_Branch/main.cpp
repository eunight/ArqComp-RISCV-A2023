#include "4_Branch.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);

	sc_clock clock("clock", period, 0.5, delay, true);

	Branch Branch("Branch");
	Testbench tb("tb");

	sc_signal<bool> dir;
	sc_signal<bool> cableA, cableB;

	Branch.addressIn(dir);
	Branch.jumpIn(cableA);
	Branch.answerOut(cableB);

	tb.addressOut(dir);
	tb.jumpOut(cableA);
	tb.answerIn(cableB);

	tb.clkIn(clock);
	Branch.clk(clock);

	sc_start();

	return 0;
}
