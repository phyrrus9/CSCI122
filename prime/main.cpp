#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
int main(int argc, char * * argv)
{
	unsigned long max = INT_MAX;
	if (argc > 1)
	{
		max = fabs(atol(argv[1]));
	}
	int divideby = (int)((double)max / 100.0);
	if (divideby <= 0)
	{
		divideby = 1;
	};
	cout << "Finding largest prime number between 0 and " << max << endl;
	sleep(5);
	unsigned long bignumber;
	cout << "begin" << endl;
	for (unsigned long i = i; i < max; i++)
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
		//progress = (i / max) * 100;
		if (i % divideby == 0)
		{
			cout << ((double)i / (double)max) * 100 << "%" << endl;
		}
	}
	cout << bignumber << endl;
	cout << "Done!" << endl;
}
