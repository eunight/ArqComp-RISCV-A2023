#include "TestBench.h"
#include <iostream>


TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName){

	SC_THREAD(test);
	sensitive << clk;

}

void TestBench::test(){
	
	std::cout << " Time    aOut    bOut    resultIn\n";
	std::cout << "---------------------------------\n";

		aOut.write(5);
		bOut.write(9);
		wait();
		print();
       	aOut.write(45);
		bOut.write(-7);
		wait();
		print();
	std::cout << "---------------------------------\n";

	sc_stop();
}

void TestBench::print()
{
	std::cout << sc_time_stamp();
	std::cout <<"     " << aOut.read().to_string();
	std::cout <<"      " << bOut.read().to_string();
	std::cout <<"     " << resultIn.read().to_string() << '\n';
}
