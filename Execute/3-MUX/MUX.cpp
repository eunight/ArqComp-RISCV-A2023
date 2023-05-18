#include "MUX.h"

Mux :: Mux(sc_module_name moduleName) : sc_module(moduleName),
	aIn("aIn"),
	bIn("bIn"),
	Op1_In("Op1_In"),
	Op2_In("Op2_In"),
	Op3_In("Op3_In"),
	Op_Out("Op_Out")
{
	SC_METHOD(process);
	sensitive << Op1_In << Op2_In << Op3_In << aIn << bIn;
}

void Mux :: process()
{
    const bool a = aIn.read();
    const bool b = bIn.read();

    if (a == false && b == false) {
        Op_Out.write(Op1_In.read());
    } 
    else if (a == true && b == false) {
        Op_Out.write(Op2_In.read());
    }
    else if (a == false && b == true) {
        Op_Out.write(Op3_In.read());
  }
}
