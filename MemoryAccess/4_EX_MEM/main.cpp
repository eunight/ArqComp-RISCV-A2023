#include <systemc.h>
#include <iostream>
#include "4_EX_MEM.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  EX_MEM EX_MEM("EX_MEM");
  Testbench tb("tb");




  sc_signal<bool> clkIn;

  sc_signal<bool> Wb_MemtoReg_1, Wb_no_idea_1 ;
  sc_signal<bool> Mem_MemWrite_1, Mem_MemRead_1, Mem_Branch_1;
 
  sc_signal<sc_int<32>> memo_1[3];
  sc_signal<sc_uint<5>> dir_1;


  sc_signal<bool> Mem_MemWrite_2, Mem_MemRead_2, Mem_Branch_2;
  sc_signal<bool> Wb_MemtoReg_2, Wb_no_idea_2 ;

  sc_signal<sc_int<32>> memo_2[4];
  sc_signal<sc_uint<5>> dir_2;

  sc_signal<bool> alu_to_brach_1, alu_to_brach_2 ;


  EX_MEM.alu_to_brachIn(alu_to_brach_1), EX_MEM.alu_to_brachOut(alu_to_brach_2);
  EX_MEM.Mem_MemWriteIn(Mem_MemWrite_1), EX_MEM.Mem_MemReadIn(Mem_MemRead_1), EX_MEM.Mem_BranchIn(Mem_Branch_1);
  EX_MEM.Mem_MemWriteOut(Mem_MemWrite_2), EX_MEM.Mem_MemReadOut(Mem_MemRead_2), EX_MEM.Mem_BranchOut(Mem_Branch_2);
  EX_MEM.Wb_MemtoRegIn(Wb_MemtoReg_1), EX_MEM.Wb_RegWriteIn(Wb_no_idea_1) ;
  EX_MEM.Wb_MemtoRegOut(Wb_MemtoReg_2), EX_MEM.Wb_RegWriteOut(Wb_no_idea_2) ;

  for(int i = 0; i< 3; i++){
    EX_MEM.memo_In[i](memo_1[i]);
  } 

  EX_MEM.dir_In(dir_1);
  

  for(int i = 0; i< 4; i++){
    EX_MEM.memo_Out[i](memo_2[i]);
  } 
  
  EX_MEM.dir_Out(dir_2);
  
  tb.alu_to_brachIn(alu_to_brach_1), tb.alu_to_brachOut(alu_to_brach_2);
  tb.Mem_MemWriteIn(Mem_MemWrite_1), tb.Mem_MemReadIn(Mem_MemRead_1), tb.Mem_BranchIn(Mem_Branch_1);
  tb.Mem_MemWriteOut(Mem_MemWrite_2), tb.Mem_MemReadOut(Mem_MemRead_2), tb.Mem_BranchOut(Mem_Branch_2);
  tb.Wb_MemtoRegIn(Wb_MemtoReg_1), tb.Wb_RegWriteIn(Wb_no_idea_1) ;
  tb.Wb_MemtoRegOut(Wb_MemtoReg_2), tb.Wb_RegWriteOut(Wb_no_idea_2) ;

  for(int i = 0; i< 3; i++){
    tb.memo_In[i](memo_1[i]);
  } 

  tb.dir_In_(dir_1);
  

  for(int i = 0; i< 4; i++){
    tb.memo_Out[i](memo_2[i]);
  } 
  
  tb.dir_Out(dir_2);


  



  EX_MEM.clkIn(clock);
  tb.clkIn(clock);

  sc_start();

  return 0;
}
