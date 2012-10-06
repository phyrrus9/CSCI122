#include <iostream>
#include <cmath>
using namespace std;
#define data_size 20
int ctoi(char c); //convert a char to an integer
void reverse(char p[]); //reverse a c-string
class big
{
private:
	int *value;
	int sign;
public:
	big();
	big(int other);
	big(const big &other);
	friend big operator+(const big & lhs, const big & rhs);
        friend big operator-(const big & lhs, const big & rhs);
        friend big operator*(const big & lhs, const big & rhs);
        friend big operator/(const big & lhs, const big & rhs);
        friend big operator%(const big & lhs, const big & rhs);

	friend int operator==(const big & lhs, const big & rhs);
        friend int operator!=(const big & lhs, const big & rhs);
        friend int operator<=(const big & lhs, const big & rhs);
        friend int operator>=(const big & lhs, const big & rhs);
        friend int operator<(const big & lhs, const big & rhs);
        friend int operator>(const big & lhs, const big & rhs);

	friend big operator-(const big & lhs);

	friend istream& operator>>(istream & lhs, big & rhs);
	friend ostream& operator<<(ostream & lhs, const big & rhs);

	big operator++(int);
	big operator--(int);

	big& operator++();
	big& operator--();
};
