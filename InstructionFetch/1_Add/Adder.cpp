#include "Adder.h"

Adder::Adder(sc_module_name moduleName) : sc_module(moduleName){
	SC_METHOD(operation);
	sensitive << aIn ;
}
void Adder::operation()
{
	resultOut.write(aIn.read() + 1);
}