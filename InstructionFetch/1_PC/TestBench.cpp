#include "TestBench.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>

Testbench::Testbench(sc_module_name mn) : sc_module(mn), adressOut("adressOut"), adressAdderIn("adressAdderIn"), adressPC_IF_IDIn("adressPC_IF_IDIn"), adressInstructionMemoryIn("adressInstructionMemoryIn"){
	SC_THREAD(test);
	sensitive << clk;
}
void Testbench::test(){
    std::cout << "\n\n*******************************************************************************\n";
	std::cout << "*  Time  |  adressAdderIn  |  adressPC_IF_IDIn  |  adressInstructionMemoryIn  *\n";
	std::cout << "*******************************************************************************\n";

	for (int i = 1; i <50; i++){
		HazardOut.write(1);
		adressOut.write(i);
		wait();
		wait();
		print();
	}
	for (int i = 1; i <50; i++){
		HazardOut.write(0);
		adressOut.write(i);
		wait();
		wait();
		print();
	}
    std::cout << "*******************************************************************************\n";
	sc_stop();
}

void Testbench::print(){
	std::cout << std::setw(7) << sc_time_stamp();
	std::cout << std::setw(17) << adressAdderIn.read().to_string();
	std::cout << std::setw(20) << adressPC_IF_IDIn.read().to_string();
	std::cout << std::setw(29) << adressInstructionMemoryIn.read().to_string() << '\n';
}