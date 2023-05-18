#include "MEM_WB.h"

MEM_WB::MEM_WB(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(operation);
	sensitive << clkIn.pos();
}

void MEM_WB::operation()
{
	for (int i = 0; i < 2; i++)
		mem_Out[i].write(mem_In[i].read());

	dir_Out.write(dir_In.read());
	Wb_MRegOut.write(Wb_MRegIn.read());
	Wb_RegWOut.write(Wb_RegWIn.read());
}
