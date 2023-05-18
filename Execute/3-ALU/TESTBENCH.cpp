#include "TESTBENCH.h"
#include <iostream>
using namespace std;

TestBench :: TestBench(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(process);
  sensitive << clk;
  dont_initialize();
}

void TestBench :: print() {

  cout << sc_time_stamp();
  cout << "        " << Op1_Out.read();
  cout << "            " << Op2_Out.read();
  cout << "             " << resultIn.read();
  cout << "\n";
}


void TestBench :: process() {
  cout << "Time    Op1_Out    Op2_Out    resultIn\n";
  cout << "--------------------------------------------\n";
  
  for (int i = 0; i < 20; i++) {

    instructOut.write(i);
    Op1_Out.write(i);
    Op2_Out.write(i+1);
    wait();
    wait();
    print();    

    cout << "-------------------------------------------\n";
  }
  sc_stop();
}
