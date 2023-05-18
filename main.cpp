//Include Instruction Fetch libraries
#include "InstructionFetch/1_Instruction_Memory/Instruction_Memory.h"
#include "InstructionFetch/1_Add/Adder.h"
#include "InstructionFetch/1_PC/1_PC.h"
#include "InstructionFetch/1_Mux/Mux.h"

//Include Instruction Decode libraries

#include "InstructionDecode/2-InstructionDecode/InstructionDecode.h"
#include "InstructionDecode/2-ImmGen/imm_gen.h"
#include "InstructionDecode/2-Registers/registers.h"

//Include Execution libraries

#include "Execute/3-ALU/ALU.h"
#include "Execute/3-ALU CONTROL/AluControl.h"
#include "Execute/3-ADDSUM/AddSum.h"
#include "Execute/3-MUX/MUX.h"

//Include Mem libraries
#include "MemoryAccess/4_Branch/4_Branch.h"
#include "MemoryAccess/4_Data_Memory/4_Data_Memory.h"
#include "MemoryAccess/4_EX_MEM/4_EX_MEM.h"

//Include WriteBack libraries

#include "WriteBack/5_WB-MUX/5_WB_Mux.h"
#include "WriteBack/5_MEM_WB/MEM_WB.h"


int sc_main(int argc, char *argv[])
{

	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

//==============================================================================================

    //Clock signal:
    
    pc.clk(clock);
    instruction_memory.clk(clock);
    if_id.clk(clock);
    registers.clk(clock);
    imm_gen.clk(clock);
    alu.clk(clock);
    ex_mem.clk(clock);
    data_memory.clk(clock);
    mem_wb.clk(clock);

	sc_start();

	return 0;
}


