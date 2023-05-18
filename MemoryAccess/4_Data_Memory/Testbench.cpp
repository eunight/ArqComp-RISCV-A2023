#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);

  sensitive << clkIn;
  dont_initialize();
}

void Testbench::print() {



    cout<<"Modulo: DATA_MEMORY (IN) \n";
    // DATA_MEMORY
   cout<<"  addressIn :"<<  addressOut.read().to_string()<<"\n";
   cout<<"  write_dataIn :"<< write_dataOut.read().to_string()<<"\n";
   cout<<"  writeIn :"<<  writeOut.read()<<"\n";
   cout<<"  readIn :"<<  readOut.read()<<"\n";
   cout<<endl;
   cout<<"Modulo: DATA_MEMORY (OUT) \n";
   cout<<"  read_dataOut :"<<  read_dataIn.read().to_string()<<"\n";

  //cout << setw(4) << clkIn.read();

  cout << "\n";  
 
}

void Testbench::test() {



    int dir[5] = {1, 1, 1, 1,1 };
    int dat[5] = {900, 22,93, 0, 89};
    //int pass[5] = {1, 1,1, 1, 1};

    for (int j = 0; j < 5;j++) {
      cout << "----------------------------------------------------------------------------\n";
      cout << "----------------------------------------------------------------------------\n";

      write_dataOut.write(dat[j]);
      addressOut.write(dir[j]); 
      readOut.write(true);            
      writeOut.write(true);            
      wait();
      print();
    }
  
  sc_stop();
}
