#ifndef ADDSUM_H
#define ADDSUM_H

#include <systemc.h>

class AddSum : public sc_module{

    public:
	    sc_in<sc_int<32>> aIn, bIn;
	    sc_out<sc_int<32>> resultOut;

	    SC_CTOR(AddSum);

    private:
	    void operation();
};

#endif
