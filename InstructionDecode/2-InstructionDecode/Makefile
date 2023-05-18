#Makefile 
SYSTEMC_HOME = /usr/local/systemc-2.3.3

# Archivos fuente
SRC = InstructionDecode.cpp testbench.cpp main.cpp 
OBJ = InstructionDecode.o testbench.o

# Opciones de compilación
CXX      = g++
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64
LDFLAGS  = -lsystemc -lm

# Nombre del ejecutable
TARGET = main

# Reglas de compilación
$(TARGET): $(OBJ) $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

InstructionDecode.o: InstructionDecode.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LDFLAGS)

testbench.o: testbench.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LDFLAGS)

.PHONY: all clean
clean:
	rm -f *.o $(TARGET)

run:
	./$(TARGET)