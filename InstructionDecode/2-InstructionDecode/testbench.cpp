#include "Testbench.h"

void Testbench::generateInstruction()
{
    instruction.write("00000000000100010000000010010011");
    rs1.write("00001");
    rs2.write("00010");
    rd.write("00011");

    wait(1, SC_NS);

    instruction.write("00000000010000010000101010010011");
    rs1.write("00101");
    rs2.write("00110");
    rd.write("00111");

    wait(1, SC_NS);

    instruction.write("00000000100000010001010110010011");
    rs1.write("01001");
    rs2.write("01010");
    rd.write("01011");

    wait(1, SC_NS);

sc_stop();

}