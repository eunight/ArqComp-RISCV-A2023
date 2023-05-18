#include "ALU.h"

ALU :: ALU(sc_module_name moduleName) : sc_module(moduleName),
	Op1_In("Op1_In"),
	Op2_In("Op2_In"),
	resultOut("resultOut")
{
	SC_METHOD(process);
	sensitive << instructIn << Op1_In << Op2_In;
	sensitive << clock.pos();
	dont_initialize();
}

//Instructions List:
// add, addi, sub, sll, slli, or, ori, and, lw, sw, beq, bne, blt, slt, slti, jal, jalr

void ALU :: process(){

    switch (instructIn.read())
    {
    case 0: //Add

        resultOut.write(Op1_In.read() + Op2_In.read());
        break;

    case 1: //Addi

        resultOut.write(Op1_.read() + Op2_In.read());
        break;

    case 2: //Sub

        resultOut.write(Op1_In.read() - Op2_In.read());
        break;

    case 3: //Sll
        {
        sc_int<32> aux1 = Op1_In.read();
	    sc_int<32> aux2 = Op2_In.read();
		resultOut.write(aux1 <<= aux2);
        break;
        }

    case 4: //Slli
        {
        sc_int<32> aux1 = Op1_In.read();
	    sc_int<32> aux2 = Op2_In.read();
		resultOut.write(aux1 <<= aux2);
        break;
        }

    case 5: //Or

        resultOut.write(Op1_In.read() or Op2_In.read());
        break;

    case 6: //Ori
    	
    	resultOut.write(Op1_In.read() or Op2_In.read());
        break;

    case 7: //And
    	resultOut.write(Op1_In.read() and Op2_In.read());
        break;
    
    case 8: //Lw//
    
    	Op1_out.write(Op1_in.read());
    	Op2_out.write(Op2_in.read());
        break;

    case 9: //Sw
    
    	Op1_out.read(Op1_in.write());
    	Op2_out.read(Op2_in.write());
        break;

    case 10: //Beq

        resultOut.write(Op1_In.read() == Op2_In.read());
        break;

    case 11: //Bne

        resultOut.write(Op1_In.read() != Op2_In.read());
        break;

    case 12: //Blt

        resultOut.write(Op1_In.read() < Op2_In.read());
        break;

    case 13: //Slt

        if (Op1_In.read() < Op2_In.read()){
            
            resultOut.write(value_1In.read());

        }

        break;


    case 14: //Slti

        if (Op1_In.read() < Op2_In.read()){
            
            resultOut.write(value_1In.read());

        }
        
        break;
    
    case 15: //Jal
    
            resultOut.write(pc + 4);
        break;

    case 16: //Jalr
    
            resultOut.write(pc + 4);
        break;


 default:
                resultOut.write(0);
                break;
    }

}

