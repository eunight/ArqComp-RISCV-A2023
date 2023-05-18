#include "TESTBENCH.h"
#include <iostream>
using namespace std;

TestBench :: TestBench(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void TestBench :: print() {
 cout << sc_time_stamp() << "        ";
 cout << Op1_Out.read() << "        ";
 cout << Op2_Out.read() << "        ";
 cout << Op3_Out.read() << "        ";
 cout << aOut.read() << "        ";
 cout << bOut.read() << "        ";
 cout << Op_In.read() << "\n";
}


void TestBench :: test() {
  cout << "Time   Op1_In   Op2_In   Op3_In   aIn   bIn   Op_Out\n";
  cout << "-------------------------------------------------------\n";

    Op1_Out.write(1);
    Op2_Out.write(2);
    Op3_Out.write(3);

    aOut.write(false);
    bOut.write(false);
    wait();
    print();

    aOut.write(true);
    bOut.write(false);
    wait();
    print();

    aOut.write(false);
    bOut.write(true);
    wait();
    print();

  sc_stop();
}
