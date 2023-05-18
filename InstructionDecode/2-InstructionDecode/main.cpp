#include <systemc.h>
#include "InstructionDecode.h"
#include "Testbench.h"

int sc_main(int argc, char *argv[])
{
    InstructionDecode decode("decode");
    Testbench tb("tb");

    sc_signal<sc_bv<32>> instruction;
    sc_signal<sc_bv<5>> rs1, rs2, rd;
    sc_signal<sc_bv<32>> imm;

    decode.instruction(instruction);
    decode.rs1(rs1);
    decode.rs2(rs2);
    decode.rd(rd);
    decode.imm(imm);

    tb.instruction(instruction);
    tb.rs1(rs1);
    tb.rs2(rs2);
    tb.rd(rd);
    tb.imm(imm);

    sc_start();

    return 0;
}