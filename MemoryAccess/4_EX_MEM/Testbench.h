#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
/*
  La logica aqui esta formada de la manera siguiente
  los nombres de los puertos de "testbench"son los nombre de los puertos de el modulo EX_MEN 
*/

  sc_in<bool> clkIn ;
  sc_in<bool> alu_to_brachOut;

  sc_out<bool> Mem_MemWriteIn, Mem_MemReadIn, Mem_BranchIn, alu_to_brachIn;
  sc_out<bool> Wb_MemtoRegIn, Wb_RegWriteIn ;

  sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
  sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut ;


  sc_out<sc_int<32>> memo_In[3];
  sc_in<sc_int<32>> memo_Out[4];

  sc_out<sc_uint<5>> dir_In_;
  sc_in<sc_uint<5>> dir_Out;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
