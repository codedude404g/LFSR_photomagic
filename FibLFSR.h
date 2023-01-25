#ifndef FIB_LFSR_H
#define FIB_LFSR_H

#include <string>
#include <fstream>

using namespace std;

class FibLFSR {
public:
	FibLFSR(string seed); 	// constructor to create LFSR with 
							// the given initial seed and tap 
	int step(); 			// simulate one step and return the 
							// new bit as 0 or 1
	int generate(int k); 			// simulate k steps and return 
									// k-bit integer
private: 
	bool data[16];

	/* friend function */
	friend ostream& operator << (ostream& out, FibLFSR t)
	{
		for (int i = 0; i < 16; ++i)
			if (t.data[i]) out << 1;
			else out << 0;
		return out;
	}
};

#endif