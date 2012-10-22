#include <iostream>
#include <cmath>
#include <limits.h>
#include "big.h"
using namespace std;
int main(int argc, char * * argv)
{
	big max = INT_MAX;
	if (argc > 1)
	{
		max = fabs(atol(argv[1]));
	}
	big divideby = max / (big)100;
	if (divideby <= 0)
	{
		divideby = 1;
	};
	cout << "Finding largest prime number between 0 and " << max << endl;
	sleep(5);
	big bignumber;
	cout << "begin" << endl;
	for (big i = i; i < max; i++)
	{
		bool prime = false;
		for (int x = 2; x < 100; x++)
		{
			if (i % x != 0 || i == x)
			{
				prime = true;
			}
			if (i % x == 0)
			{
				prime = false;
			}
		}
		if (prime)
		{
			prime = false;
			bignumber = i;
			cout << "Prime number found " << i << endl;
		}
	}
	cout << bignumber << endl;
	cout << "Done!" << endl;
}
