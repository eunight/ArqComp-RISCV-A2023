#include "ALU.h"
#include "TESTBENCH.h"

int sc_main(int argv, char* argc[]) {

  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  ALU alu("alu");
  TESTBENCH testbench("testbench");

  sc_signal<sc_int<32>> Op1, Op2, result;
  sc_signal<sc_uint<5>> instruct;


  alu.Op1_In(Op1);
  alu.Op2_In(Op2);
  alu.instructIn(instruct);
  alu.resultOut(result);
  alu.clk(clock);


  testbench.resultIn(result);
  testbench.Op1_Out(Op1);
  testbench.Op2_Out(Op2);
  testbench.instructOut(instruct);


  testbench.clk(clock);

  sc_start();

  return 0;
}
