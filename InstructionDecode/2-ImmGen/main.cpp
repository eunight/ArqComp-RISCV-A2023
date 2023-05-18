#include <systemc.h>
#include "imm_gen.h"
#include "testbench.h"

int sc_main(int argc, char* argv[]) {
  sc_signal<sc_uint<32>> instruction, imm;

  ImmGen imm_gen("imm_gen");
  imm_gen.instruction(instruction);
  imm_gen.imm(imm);

  Testbench testbench("testbench");
  testbench.instruction(instruction);
  testbench.imm(imm);

  sc_start();

  return 0;
}