#include "4_EX_MEM.h"

EX_MEM::EX_MEM(sc_module_name nm) : sc_module(nm)
{

	SC_METHOD(operation);
	sensitive << clkIn.pos();
}

void EX_MEM::operation()
{
	if (Mem_MemWriteIn.read() or Mem_MemReadIn.read())
	{
		try
		{
			if (memo_In[1].read() < 0 || memo_In[1].read() >= 256)
				throw 0;
		}
		catch (...)
		{
			std::cout << "\n\nAcceso a Cache L1 de Datos fuera de límites\n\n";
			sc_stop();
		}
	}

	for (int i = 0; i < 3; i++){
		memo_Out[i].write(memo_In[i].read());
	}
	memo_Out[3].write(memo_In[1].read());//esto es para pasar la ramificacion que se hace en mem
											 //debido a que como ya se divide el cable para dirigirlo a 
											 //el testbench, no se puede dividir mas

	dir_Out.write(dir_In.read());
	alu_to_brachOut.write(alu_to_brachIn.read());
	Mem_MemWriteOut.write(Mem_MemWriteIn.read());
	Mem_MemReadOut.write(Mem_MemReadIn.read());
	Mem_BranchOut.write(Mem_BranchIn.read());
	Wb_MemtoRegOut.write(Wb_MemtoRegIn.read());
	Wb_RegWriteOut.write(Wb_RegWriteIn.read());
}
