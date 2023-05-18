#include "registers.h"

void Registers::read_registers() {
  data1.write(regs[rd1.read()]);
  data2.write(regs[rd2.read()]);
}

void Registers::write_registers() {
  if (wen.read() == SC_LOGIC_1) {
    regs[wd.read()] = data2.read();
  }
}