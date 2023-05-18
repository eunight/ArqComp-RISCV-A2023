#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {
  cout<<" \n MEM_WB (IN)...\n";
  cout<<" \n WB_MRegIn :"<<  Wb_MRegIn.read()<<"\n";
  cout<<" \n WB_RegWIn :"<<  Wb_RegWIn.read()<<"\n";
  cout<<" \n MEM_In[0] :"<<  mem_In[0].read().to_string()<<"\n";
  cout<<" \n MEM_In[1] :"<<  mem_In[1].read().to_string()<<"\n";
  cout<<" \n dir_In :"<<  dir_In.read().to_string()<<"\n";
  cout<<endl;  
  cout << " \n EX MEM (OUT)...\n";
  cout << " \n aIWb_MRegOutn :" << Wb_MRegOut.read() << "\n"; 
  cout << " \n WB_RegWOut :" << Wb_RegWOut.read() << "\n";    
  cout << " \n MEM_Out[0] (MemWb_muxWb1):" << mem_Out[0].read().to_string() << "\n";
  cout << " \n MEM_Out[1] (MemWb_muxWb2):" << mem_Out[1].read().to_string() << "\n";
  cout << " \n dir_Out :" << dir_Out.read().to_string() << "\n";
  cout << endl;

  cout << "\n";
}


void Testbench::test() {


  int b[] = {23,126,89,554,20, 222,66};
  int a[] = { 44, 434, 240, 155,203,22,196};
  for(int i = 0; i < 4; i++){
   cout << "-------------------------------\n";
   
   mem_In[(i % 2)].write(a[i]);
    dir_In.write(b[i] % 32);
    Wb_MRegIn.write((i + 1) % 2);
    Wb_RegWIn.write((i + 1) % 2); 
    wait();
    print();    
  }



  
  sc_stop();
}
