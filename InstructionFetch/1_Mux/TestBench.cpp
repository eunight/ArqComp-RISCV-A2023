#include "TestBench.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName), clk("clk"), sOut("sOut"), aOut("aOut"), bOut("bOut"), cIn("cIn"){
	SC_THREAD(test);
	sensitive << clk;
}

void Testbench::test(){
	srand(time(NULL));
	sc_int<32> a, b;
	std::cout << "\n\n*******************************************\n";
	std::cout << "* Time  |  bOut  |  aOut  |  sOut  |  cIn *\n";
	std::cout << "*******************************************\n";

	for (int i = 0; i < 10; i++)
	{
		a = rand() % 200;
		b = a * 2;
		aOut.write(a);
		bOut.write(b);
		sOut.write(i % 2);
		wait();
		print();
	}

	std::cout << "\n*******************************************\n";
	sc_stop();
}

void Testbench::print(){
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(8) << bOut.read().to_string();
	std::cout << std::setw(8) << aOut.read().to_string();
	std::cout << std::setw(8) << sOut.read();
	std::cout << std::setw(7) << cIn.read().to_string() << '\n';
}