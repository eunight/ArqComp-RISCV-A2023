#include <systemc.h>
#include "registers.h"
#include "testbench.h"

int sc_main(int argc, char* argv[]) {
  sc_clock clk("clk", 10, SC_NS);

  sc_signal<sc_uint<5>> rd1, rd2, wd;
  sc_signal<sc_logic> wen;
  sc_signal<sc_uint<32>> data1, data2;

  Registers registers("registers");
  registers.clk(clk);
  registers.rd1(rd1);
  registers.rd2(rd2);
  registers.wd(wd);
  registers.wen(wen);
  registers.data1(data1);
  registers.data2(data2);

  Testbench testbench("testbench");
  testbench.clk(clk);
  testbench.rd1(rd1);
  testbench.rd2(rd2);
  testbench.wd(wd);
  testbench.wen(wen);
  testbench.data1(data1);
  testbench.data2(data2);

  sc_start();

  return 0;
}