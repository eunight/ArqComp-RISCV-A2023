#include "PC.h"

PC::PC(sc_module_name mn) : sc_module(mn), adressIn("adressIn"), adressAdderOut("adressAdderOut"), adressPC_IF_IDOut("adressPC_IF_IDOut"), adressInstructionMemoryOut("adressInstructionMemoryOut") {
	SC_METHOD(write);
	sensitive << clk.pos();

	SC_METHOD(read);
	sensitive << clk.neg();
}

void PC::write() {
	if(HazardIn.read() !=1 ){
		adressInstructionMemoryOut.write(adress);
		adressAdderOut.write(adress);
		adressPC_IF_IDOut.write(adress);
	}
}

void PC::read() {
	adress = adressIn.read();
}