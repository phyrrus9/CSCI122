#include "big.h"

int main()
{
	cout << "Data size: " << sizeof(big) << endl;
	int i;
	big newbie, addval;
	cout << "1: ";
	cin >> newbie;
	cout << "2. ";
	cin >> addval;
	cout << newbie << "*"<< addval << "=" << operator*(newbie,addval) << endl;
}
