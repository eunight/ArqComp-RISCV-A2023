#include "Instruction_Memory.h"
#include "TestBench.h"

int sc_main(int argc, char* argv[]){
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 5, delay, true);
	InstructionMemory instructionMemory("instructionMemory");
	Testbench tb("tb");
	sc_signal<sc_int<32>> instructionNumberSg;
	sc_signal<sc_uint<32>> operationSg;
	tb.clk(clock);
	instructionMemory.clk(clock);
	instructionMemory.instructionNumberIn(instructionNumberSg);
	tb.instructionNumberOut(instructionNumberSg);
	instructionMemory.operationOut(operationSg);
	tb.operationIn(operationSg);
	sc_start();
	return 0;
}