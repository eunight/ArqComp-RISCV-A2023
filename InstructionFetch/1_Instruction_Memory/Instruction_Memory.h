#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H
#include <systemc.h>
#include <fstream>
#include <string>

class InstructionMemory : public sc_module {
  public:
    sc_in_clk clk;
    sc_in<sc_int<32>> instructionNumberIn;
    sc_out<sc_uint<32>> operationOut;
    SC_CTOR (InstructionMemory);

  private:
    sc_uint<32> operand;
    sc_int<17> numOfInstructions;
    std::string *instructionsList;
    void operation();
    void list(std::string);
    inline void registerValidation(sc_int<32> dir);
    inline void immValidation(sc_int<32> dir);
};
#endif