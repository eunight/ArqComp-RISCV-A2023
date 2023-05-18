#include "TestBench.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Testbench::Testbench(sc_module_name TB_InstructionMemory) : sc_module(TB_InstructionMemory), clk("clk"), instructionNumberOut("instructionNumberOut"), operationIn("operationIn"){
	SC_THREAD(test);
	sensitive << clk;
	dont_initialize();
}
void Testbench::test(){
	wait();
	std::cout << "\n\n*****************************************************************\n";
	std::cout << "*  Time  |   OpCode   |   rs1    |   rs2   |    rd    |    imm  *\n";
	std::cout << "*****************************************************************\n";

	// Si Instruction Memory es sensible a la entrada, la lectura de la linea 0 no la detecta, si no que es la lectura por defecto al principio del programa. Por esto, basta con colocar un wait aca y ya tendremos la lectura de la primera linea. En este caso, el for empezara a partir de 1 (0 ya lo leyo)

	for (int i = 1; i < 10; i++){
		instructionNumberOut.write(i);
		// Al estar sincronizado con reloj, el testbench debe esperar un ciclo completo para obtener respuesta de Instruction Memory, debido a la lectura y escritura sobre los puertos
		wait();
		wait();

	    for (sc_uint<5> i = 0; i < 5; i++){
		    opCode[i] = operationIn.read()[i];
		}

    	for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++){
    		rs1[j] = operationIn.read()[i];
	    }

    	for (sc_uint<6> i = 10, j = 0; i < 15; i++, j++){
	    	rs2[j] = operationIn.read()[i];
    	}

    	for (sc_uint<6> i = 15, j = 0; i < 20; i++, j++){
	    	rd[j] = operationIn.read()[i];
	    }

	    for (sc_uint<6> i = 20, j = 0; i < 32; i++, j++){
			imm[j] = operationIn.read()[i];
		}
    	print();
	}

	std::cout << "\n*****************************************************************\n";

	sc_stop();
}

void Testbench::print(){
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(8) << opCode.to_string();
	std::cout << std::setw(10) << rs1.to_string();
	std::cout << std::setw(10) << rs2.to_string();
	std::cout << std::setw(10) << rd.to_string();
	std::cout << std::setw(10) << imm.to_string() << endl;
}