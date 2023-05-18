#include "4_Data_Memory.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, false);
  //sc_clock clock("clock", 10, true);
 
  Data_Memory Data_Memory("Data_Memory");
  Testbench tb("tb");

  sc_signal<sc_int<32>> dir;
  sc_signal<sc_int<32>> result, cable;  
  sc_signal<bool> write, cable_1, cable_2;

  Data_Memory.addressIn(dir);  
  Data_Memory.read_dataOut(result); 
  Data_Memory.write_dataIn(cable); 
  Data_Memory.writeIn(cable_1); 
  Data_Memory.readIn(cable_2); 



  tb.addressOut(dir);  
  tb.write_dataOut(cable);  
  tb.read_dataIn(result);
  tb.writeOut(cable_1); 
  tb.readOut(cable_2); 


   //tb.memory = Data_Memory.memory;

  Data_Memory.clkIn(clock);
  tb.clkIn(clock);



  sc_start();

  return 0;
}
