#include "AluControl.h"

AluControl::id_ex(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(process);
	sensitive << clkIn.neg();
	dont_initialize();
}

void AluControl :: process()
{
	rs1Out.write(rs1In.read());
    Ex_ALUOut.write(Ex_ALUIn.read());

    if (imm_genIn.read() == 0){
        rs2Out.write(rs2In.read());
    }
    else {
        rs2Out.write(imm_genIn.read());
    }

    rs1_registerOut.write(rs1_registerIn.read());
    rs2_registerOut.write(rs2_registerIn.read());
    target_registerOut.write(target_registerIn.read());



}
