#include "AddSum.h"

AddSum::AddSum(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << aIn << bIn;

}

void AddSum::operation()
{
	resultOut.write(aIn.read() + bIn.read());
}
