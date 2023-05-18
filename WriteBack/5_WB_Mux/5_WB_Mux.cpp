#include "5_WB_Mux.h"

Mux::Mux(sc_module_name moduleName) : sc_module(moduleName), sIn("sIn"), aIn("aIn"), bIn("bIn"), cOut("cOut")
{
	SC_METHOD(operation);
	sensitive << aIn << bIn << sIn;
}

void Mux::operation()
{
	if (sIn.read())
		cOut.write(bIn.read());
	else
		cOut.write(aIn.read());
}