#ifndef BRANCH_H
#define BRANCH_H

#include <systemc.h>


class Branch : public sc_module
{
public:
	sc_in_clk clk;
	sc_in<bool> jumpIn, addressIn;
	sc_out<bool> answerOut;

	SC_CTOR(Branch);

private:
	void operation();
};

#endif
