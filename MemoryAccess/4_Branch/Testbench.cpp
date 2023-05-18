#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {
  cout << setw(6) << sc_time_stamp();
  cout << setw(6) << "";
  cout << setw(6) << addressOut.read() ;
  cout << setw(6) << "";
  cout << setw(6) << jumpOut.read();
  cout << setw(6) << "";
  cout << setw(6) << answerIn.read();
  cout << setw(6) << "";
  cout << setw(6) << clkIn.read();
  cout << setw(6) << "";
  cout << "\n";
}


void Testbench::test() {
  cout << "Tiempo    addressOut    jumpOut    answerIn    clkIn\n";
  cout << "----------------------------------------------------------------------------------\n";



  int a[] = { 1, 1, 1, 0, 0,1, 0};
  int b[] = { 1, 0, 1, 1, 0,1, 0};
  

  for (int j = 0; j < 7; j++) {
    addressOut.write(a[j]);
    jumpOut.write(b[j]);
    wait();
    print();    
    cout << "---------------------------------------------------------------------------------\n";
  }
  sc_stop();
}
