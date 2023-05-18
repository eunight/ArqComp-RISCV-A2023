
# Versión de SYSTEMC
	VERSION = systemc-2.3.3
# Especifique los archivos .cpp
	SRCS = Adder.cpp TestBench.cpp main.cpp
# Nombre del ejecutable
	TARGET = test


CC  = g++
X64 = 
SYSTEMC_HOME_BY_VERSION = /usr/local/$(VERSION)

ifeq ($(shell uname -m), x86_64)
	X64 = 64
endif

ifeq ($(VERSION),systemc-2.3.1)
	CC = g++ -std=c++98
endif

INCDIR  = -I. -I.. -I$(SYSTEMC_HOME_BY_VERSION)/include
LIBDIR  = -L. -L.. -L$(SYSTEMC_HOME_BY_VERSION)/lib-linux$(X64)
LIBS    = -lm -lsystemc

CFLAGS  = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)

.SUFFIXES: .cpp .o

$(TARGET): $(OBJS) $(SRCH)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

all: $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(TARGET) *.bak $(TARGET).stackdump *.vcd

run:
	./$(TARGET)