#include "MEM_WB.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  MEM_WB me_wb("me_wb");
  Testbench tb("tb");


  sc_signal<bool> clkIn;

  sc_signal<bool> Wb_MReg_1, Wb_RegW_1 ;
  sc_signal<sc_int<32>> mem_1[2];
  sc_signal<sc_uint<5>> dir_1;

  sc_signal<bool> Wb_MReg_2, Wb_RegW_2 ;
  sc_signal<sc_int<32>> mem_2[2];
  sc_signal<sc_uint<5>> dir_2;



  me_wb.Wb_MRegIn(Wb_MReg_1), me_wb.Wb_RegWIn(Wb_RegW_1) ;
  me_wb.Wb_MRegOut(Wb_MReg_2), me_wb.Wb_RegWOut(Wb_RegW_2) ;
  me_wb.dir_In(dir_1);
  me_wb.dir_Out(dir_2);

  for(int i = 0; i< 2; i++){
    me_wb.mem_In[i](mem_1[i]);
  } 

  
  for(int i = 0; i< 2; i++){
    me_wb.mem_Out[i](mem_2[i]);
  } 
  
  

  tb.Wb_MRegIn(Wb_MReg_1), tb.Wb_RegWIn(Wb_RegW_1) ;
  tb.Wb_MRegOut(Wb_MReg_2), tb.Wb_RegWOut(Wb_RegW_2) ;
  tb.dir_In(dir_1);
  tb.dir_Out(dir_2);

  for(int i = 0; i< 2; i++){
    tb.mem_In[i](mem_1[i]);
  } 

  for(int i = 0; i< 2; i++){
    tb.mem_Out[i](mem_2[i]);
  } 

  me_wb.clkIn(clock);
  tb.clkIn(clock);

  sc_start();

  return 0;
}
