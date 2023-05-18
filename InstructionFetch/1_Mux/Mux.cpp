#include "Mux.h"

Mux1::Mux1(sc_module_name moduleName) : sc_module(moduleName), sIn("sIn"), aIn("aIn"), bIn("bIn"), cOut("cOut"){
	SC_METHOD(operation);
	sensitive << aIn << bIn << sIn;
}

void Mux1::operation(){
	if (sIn.read() == 1)
		cOut.write(bIn.read());//entrada del adder en la etapa id
	else
		cOut.write(aIn.read());// entrada de adder en la etapa if
}
