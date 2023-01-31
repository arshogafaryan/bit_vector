#include "bit_vector.h"

int main()
{
	bit_vector<100> bv;
	bv.set(32);
	bv.set(99);
	bv.set(0);
	bv.reset(99);
	return 0;
}
