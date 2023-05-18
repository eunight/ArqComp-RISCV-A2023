#include "AluControl.h"
#include "TESTBENCH.h"


int sc_main(int argv, char* argc[]) {

    sc_time period(10,SC_NS);
    sc_time delay(0,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, true);

    AluControl AluControl("AluControl");
    TestBench TestBench("TestBench");

    sc_signal<sc_int<32>> rs1OutSg, rs2OutSg, imm_genOutSg;
    sc_signal<sc_uint<5>> rs1_registerOutSg, rs2_registerOutSg, target_registerOutSg, AluIns1Sg;

    sc_signal<sc_int<32>> rs1InSg, rs2InSg;
    sc_signal<sc_uint<5>> rs1_registerInSg, rs2_registerInSg, target_registerInSg, AluIns2Sg;

    sc_signal<bool> HazardSg, MemWrite1Sg, MemRead1Sg, MuxWb1Sg, RegWrite1WbSg;
    sc_signal<bool> MemWrite2Sg, MemRead2Sg, MuxWb2Sg, RegWrite2WbSg;
    
    AluControl.rs1In(rs1OutSg);
    AluControl.rs2In(rs2OutSg);
    AluControl.imm_genIn(imm_genOutSg);
    AluControl.rs1_registerIn(rs1_registerOutSg);
    AluControl.rs2_registerIn(rs2_registerOutSg);
    AluControl.target_registerIn(target_registerOutSg);
    AluControl.HazardIn(HazardSg);
    AluControl.Mem_MemWriteIn(MemWrite1Sg);
    AluControl.Mem_MemReadIn(MemRead1Sg);
    AluControl.Wb_MemtoRegIn(MuxWb1Sg);
    AluControl.Wb_RegWriteIn(RegWrite1WbSg);
    AluControl.Ex_ALUIn(AluIns1Sg);

    AluControl.rs1Out(rs1InSg);
    AluControl.rs2Out(rs2InSg);
    AluControl.rs1_registerOut(rs1_registerInSg);
    AluControl.rs2_registerOut(rs2_registerInSg);
    AluControl.target_registerOut(target_registerInSg);
    AluControl.Mem_MemWriteOut(MemWrite2Sg);
    AluControl.Mem_MemReadOut(MemRead2Sg);
    AluControl.Wb_MemtoRegOut(MuxWb2Sg);
    AluControl.Wb_RegWriteOut(RegWrite2WbSg);
    AluControl.Ex_ALUOut(AluIns2Sg);


    TestBench.rs1In(rs1InSg);
    TestBench.rs2In(rs2InSg);
    TestBench.rs1_registerIn(rs1_registerInSg);
    TestBench.rs2_registerIn(rs2_registerInSg);
    TestBench.target_registerIn(target_registerInSg);
    TestBench.Mem_MemWriteIn(MemWrite2Sg);
    TestBench.Mem_MemReadIn(MemRead2Sg);
    TestBench.Wb_MemtoRegIn(MuxWb2Sg);
    TestBench.Wb_RegWriteIn(RegWrite2WbSg);
    TestBench.Ex_ALUIn(AluIns2Sg);

    TestBench.rs1Out(rs1OutSg);
    TestBench.rs2Out(rs2OutSg);
    TestBench.imm_genOut(imm_genOutSg);
    TestBench.rs1_registerOut(rs1_registerOutSg);
    TestBench.rs2_registerOut(rs2_registerOutSg);
    TestBench.target_registerOut(target_registerOutSg);
    TestBench.HazardOut(HazardSg);
    TestBench.Mem_MemWriteOut(MemWrite1Sg);
    TestBench.Mem_MemReadOut(MemRead1Sg);
    TestBench.Wb_MemtoRegOut(MuxWb1Sg);
    TestBench.Wb_RegWriteOut(RegWrite1WbSg);
    TestBench.Ex_ALUOut(AluIns1Sg);


       
    
    AluControl.clkIn(clock);

    TestBench.clkIn(clock);

    sc_start();

  return 0;
}
