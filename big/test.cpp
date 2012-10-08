#include "big.h"

int main()
{
	cout << "Data size: " << sizeof(big) << endl;
	int i;
	big newbie, addval;
	cout << "? ";
	cin >> newbie;
	cout << "n ";
	cin >> addval;
	cout << newbie << "/"<< addval << "=" << newbie / addval << endl;
}
