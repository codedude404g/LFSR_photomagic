#include "FibLFSR.h"

FibLFSR::FibLFSR(string seed)
{
	for (int i = 0; i < 16; ++i)
		if (seed[i] == '1')
			data[i] = 1;
		else data[i] = 0;
}

int FibLFSR::step()
{
	char mostleft = data[0];
	mostleft ^= data[2];
	mostleft ^= data[3];
	mostleft ^= data[5];
	
	for (int i = 0; i < 16 - 1; ++i)
		data[i] = data[i + 1];
	data[15] = mostleft;
	return mostleft;
}

int FibLFSR::generate(int k)
{
	int x = 0;
	while (k)
	{
		x = 2 * x + step();
		k--;
	}
	return x;
}