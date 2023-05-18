#include "testbench.h"

void Testbench::monitor() {
  wait(clk.posedge_event());
  cout << "Data1: " << data1.read() << endl;
  cout << "Data2: " << data2.read() << endl;

  sc_stop();
}