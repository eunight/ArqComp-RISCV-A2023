#include "testbench.h"

void Testbench::test() {
  // Prueba de ejemplo: enviar una instrucción e imprimir el valor inmediato resultante
  instruction.write(0b00000110010000100000000000100011);  // I-type instruction
  wait(1);
  cout << "Immediate: " << imm.read() << endl;

  sc_stop();
}