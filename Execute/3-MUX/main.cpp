#include "MUX.h"
#include "TESTBENCH.h"

int sc_main(int argv, char* argc[]) {


  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);


  sc_clock clock("clock", period, 0.5, delay, true);

 
  Mux Mux("Mux");
  TestBench TestBench("TestBench");

 
  sc_signal<sc_int<32>> Op1_Sg, Op2_Sg, Op3_Sg, OpSg;
  sc_signal<bool> aSg, bSg;

 
  Mux.Op1_In(Op1_Sg);
  Mux.Op2_In(Op2_Sg);
  Mux.Op3_In(Op_3Sg);
  Mux.aIn(aSg);
  Mux.bIn(bSg);
  Mux.Op_Out(OpSg);

  TestBench.Op_In(OpSg);
  TestBench.Op1_Out(Op1_Sg);
  TestBench.Op2_Out(Op2_Sg);
  TestBench.Op3_Out(Op3_Sg);
  TestBench.aOut(aSg);
  TestBench.bOut(bSg);

  
  TestBench.clkIn(clock);

  
  sc_start();

  return 0;
}
