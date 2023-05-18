#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {

  cout << "Modulo:  EX MEN (IN)------------------------\n";
  cout << "  alu_to_brachIn :" << alu_to_brachIn.read() << "\n";
  cout << "  Mem_MemWriteIn :" << Mem_MemWriteIn.read() << "\n";
  cout << "  Mem_MemReadIn :" << Mem_MemReadIn.read() << "\n";
  cout << "  Mem_BranchIn :" << Mem_BranchIn.read() << "\n";
  cout << "  Wb_MemtoRegIn :" << Wb_MemtoRegIn.read() << "\n";
  cout << "  Wb_RegWriteIn :" << Wb_RegWriteIn.read() << "\n";
  cout << "  memo_In[0] (addSum_exMem) :" << memo_In[0].read().to_string() << "\n";
  cout << "  memo_In[1] (alu_exMem_32bit):" << memo_In[1].read().to_string() << "\n";
  cout << "  memo_In[2] (idEx_muxEx_exMem):" << memo_In[2].read().to_string() << "\n";
  cout << "  dir_In_ :" << dir_In_.read().to_string() << "\n";

   cout<<"Modulo: EX MEM (OUT)------------------------\n";
   cout<<"  alu_to_brachOut :"<<  alu_to_brachOut.read()<<"\n";
   cout<<"  Mem_MemWriteOut :"<<  Mem_MemWriteOut.read()<<"\n";
   cout<<"  Mem_MemReadOut :"<<  Mem_MemReadOut.read()<<"\n";
   cout<<"  Mem_BranchOut :"<<  Mem_BranchOut.read()<<"\n";
   cout<<"  Wb_MemtoRegOut :"<< Wb_MemtoRegOut.read()<<"\n";
   cout<<"  Wb_RegWriteOut :"<<  Wb_RegWriteOut.read()<<"\n";
   cout<<"  memo_Out[0] (exMem_muxPC):"<< memo_Out[0].read().to_string()<<"\n";
   cout<<"  memo_Out[1] (exMem_dataMemoryAddress):"<< memo_Out[1].read().to_string()<<"\n";
   cout<<"  memo_Out[2] (exMem_dataMemoryData):"<< memo_Out[2].read().to_string()<<"\n";
   cout<<"  memo_Out[3] (exMem_MemWb32bits):"<< memo_Out[3].read().to_string()<<"\n";
    cout << "  dir_Out :" << dir_Out.read().to_string() << "\n";

  cout << "\n";
}


void Testbench::test() {


  int b[] = { 42, 32, 53, 74,10,1,16};
  int a[] = { 4, 2, 3, 4,10,12,176};
  int help = 0;// esto es solo para poder demostrar los 4 puertos, pues si dejaba el ciclo
           // for en 3 no podriamos probar el ultimo puesto (memo[2])
  for(int i = 0; i < 4; i++){
   cout << "-----------------------------\n";
   if(i >= 3){
      help = 1;
   }
    memo_In[i- help].write(a[i]);
    dir_In_.write(b[i]);

    alu_to_brachIn.write((i + 1) % 2);

    Mem_MemWriteIn.write((i + 1) % 2); 
    Mem_MemReadIn.write((i + 1) % 2);
    Mem_BranchIn.write((i + 1) % 2);
    Wb_MemtoRegIn.write((i + 1) % 2);
    Wb_RegWriteIn.write((i + 1) % 2); 
    wait();
    print();    
  }



  
  sc_stop();
}
