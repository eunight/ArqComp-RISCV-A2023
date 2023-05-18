#include "InstructionDecode.h"

void InstructionDecode::decodeInstruction()
{
    sc_uint<7> opcode = instruction.read().range(6, 0).to_uint();
    sc_uint<7> funct3 = instruction.read().range(14, 12).to_uint();
    sc_uint<7> funct7 = instruction.read().range(31, 25).to_uint();

    // Decodificar la instrucción y generar el valor inmediato
    if (opcode == 0x13) // I-Type Instructions
    {
        switch (funct3)
        {
            case 0x0: // addi
            case 0x4: // slli
            case 0x6: // ori
            case 0x7: // andi
                imm.write(instruction.read().range(31, 20));
                break;
            default:
                imm.write(sc_bv<32>(0));
                break;
        }
    }
    else if (opcode == 0x3) // Load Instructions
    {
        imm.write(instruction.read().range(31, 20));
    }
    else if (opcode == 0x23) // Store Instructions
    {
        imm.write(instruction.read().range(31, 25) << 5 | instruction.read().range(11, 7));
    }
    else
    {
        imm.write(sc_bv<32>(0));
    }
}