#include "TESTBENCH.h"
#include <iostream>
using namespace std;

TestBench :: TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}

void TestBench :: print() {
  cout << sc_time_stamp() << "   ";
  cout << rs1Out.read() << "     ";
  cout << rs2Out.read() << "        ";
  cout << imm_genOut.read() << "             ";
  cout << rs1_registerOut.read() << "              ";
  cout << rs2_registerOut.read() << "                 ";
  cout << target_registerOut.read() << "            ";
  cout << rs1In.read() << "     ";
  cout << rs2In.read() << "       ";
  cout << rs1_registerIn.read() << "               ";
  cout << rs2_registerIn.read() << "             ";
  cout << target_registerIn.read() << "\n";
  cout<< "\nWrite enable seniales de control: " << HazardOut.read();
  cout << "\nMemWrite: " <<  Mem_MemWriteIn.read();
  cout << "\nMemRead: " <<  Mem_MemReadIn.read();
  cout << "\nWBMux: " << Wb_MemtoRegIn.read();
  cout << "\nRegWrite: " <<   Wb_RegWriteIn.read();
}
void TestBench :: test() {

cout << "Time rs1Out rs2Out imm_genOut rs1_registerOut rs2_registerOut target_registerOut rs1In rs2In rs1_registerIn rs2_registerIn target_registerIn\n";
cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";

    Ex_ALUOut.write(1515415);
    rs1Out.write(1);
    rs2Out.write(0);
    imm_genOut.write(1);
    rs1_registerOut.write(0);
    rs2_registerOut.write(1);
    target_registerOut.write(0);
    target_registerOut.write(0); 
    wait();
    wait();
    print();

    rs1Out.write(1);
    rs2Out.write(0);
    imm_genOut.write(1);
    rs1_registerOut.write(0);
    rs2_registerOut.write(1);
    target_registerOut.write(0);

    Ex_ALUOut.write(1515415);
    wait();
    wait();
    print();




  sc_stop();
}
