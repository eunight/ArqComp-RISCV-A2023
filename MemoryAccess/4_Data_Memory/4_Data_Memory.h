#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <systemc.h>
const int TAM_MEMORY__MEM = 256;

class Data_Memory: public sc_module {
public:

  sc_in<sc_int<32>> addressIn;    
  sc_out<sc_int<32>> read_dataOut;     
  sc_in<sc_int<32>> write_dataIn;    
  sc_in<bool> writeIn, readIn;       

  sc_in<bool> clkIn;        //reloj (para controlar el momento de lectura y el momento de escritura)
  sc_vector<sc_signal<sc_int<32>>> SC_NAMED(memory, TAM_MEMORY__MEM);

  SC_CTOR(Data_Memory);

private:
  void read();
  void write();

};

#endif
