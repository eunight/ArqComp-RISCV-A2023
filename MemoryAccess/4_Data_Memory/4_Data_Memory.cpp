#include "4_Data_Memory.h"

Data_Memory::Data_Memory(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(write);
	sensitive << clkIn.pos();

	SC_METHOD(read);
	sensitive << clkIn.neg();
}

void Data_Memory::write()
{
	if (writeIn.read())
	{
		memory[addressIn.read()] = write_dataIn.read();
	}
}

void Data_Memory::read()
{
//	std::cout << "estoy leyendo " << addressIn.read() << '\n';
	if (readIn.read())
	{
		read_dataOut.write(memory[addressIn.read()]);
	}
}
