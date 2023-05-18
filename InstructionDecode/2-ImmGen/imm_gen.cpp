#include "imm_gen.h"

void ImmGen::generate_imm() {
  sc_uint<32> opcode = instruction.read().range(6, 0);
  sc_uint<32> imm_result;

  switch (opcode) {
    case 0b0010011:  // I-type instructions
    case 0b0000011:  // Load instructions
    case 0b1100111:  // Jalr instruction
      imm_result = instruction.read().range(31, 20);
      imm.write(imm_result);
      break;

    case 0b0100011:  // Store instructions
      imm_result = (instruction.read().range(31, 25), instruction.read().range(11, 7));
      imm.write(imm_result);
      break;

    case 0b1101111:  // Jal instruction
      imm_result = (instruction.read().range(31, 31), instruction.read().range(19, 12), instruction.read().range(20, 20),
                    instruction.read().range(30, 21));
      imm.write(imm_result);
      break;

    default:
      imm.write(0);  // Default value
      break;
  }
}