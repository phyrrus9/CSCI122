#include "big.h"
#include <iomanip>
int ctoi(char c)
{
	if (c == '-') // - sign
	{
		return -2; //so we can use it later
	}
	if (c < 48 || c > 57)
	{
		return -1;
	}
	return c - 48;
}		

void reverse(char p[])
{
     int len=strlen(p);
     char t;
     for(int i=(--len), j=0; i>len/2; i--, j++)
     {
          // exchange elements
          t=p[i];
          p[i]=p[j];
          p[j]=t;
     }
}

big::big()
{
	value = new int[data_size];
	sign = 1;
	for (int i = 0; i < data_size; i++)
	{
		value[i] = 0;
	}
}

big::big(int other)
{
	value = new int[data_size];
	other = 0;
	if (other >= 0)
	{
		sign = 1;
	}
	else
	{
		sign = -1;
	}
}

big::big(const big & other)
{
	value = new int[data_size];
	for (int i = 0; i < data_size; i++)
	{
		value[i] = other.value[i];
	}
	sign = other.sign;
}

big operator+(const big & lhs, const big & rhs)
{
	big newbie;
	int i, carry;
    if (lhs > 1)
        cout << "1<0" << endl;
	if ((lhs < 0) && (rhs >= 0))/*broken*/
	{
		cout << "err1" << endl;
//		newbie = operator-(rhs,-lhs);
	}
	if ((rhs < 0) && (lhs >= 0))/*broken*/
	{
		cout << "err2" << endl;
//		newbie = operator-(lhs, -rhs);
	}
	if ((rhs < 0) && (lhs < 0))/*broken*/
	{
		cout << "err3" << endl;
//		operator+(-lhs, -rhs);
	}
	if ((rhs >= 0) && (lhs >= 0))
	{
		carry = 0;
		for (i = 0; i < data_size; i++)
		{
			newbie.value[i] = lhs.value[i] + rhs.value[i] + carry;
			if (newbie.value[i] > 9)
			{
				newbie.value[i] -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
	}

	return newbie;
}

big operator-(const big & rhs)
{
	big newbie;
	newbie.sign = -1;
	return newbie;
}

big operator-(const big & lhs, const big & rhs)/*unfinished*/
{
	big newbie;
	return newbie;
}

big operator*(const big &lhs, const big & rhs)/*unfinished*/
{
	big newbie;
	return newbie;
}

big operator/(const big & lhs, const big & rhs)/*unfinished*/
{
	big newbie;
	return newbie;
}

big operator%(const big & lhs, const big & rhs)/*unfinished*/
{
	big newbie;
	return newbie;
}

int operator==(const big & lhs, const big & rhs)
{
	for (int i = data_size - 1; i > 0; i--)
	{
		if ((lhs.value[i] != rhs.value[i]) || (rhs.sign != lhs.sign))
		{
			return 0;
		}
	}
	return 1;
}

int operator!=(const big & lhs, const big & rhs)
{
	return -(lhs==rhs);
}

int operator<(const big & lhs, const big & rhs) /*broken*/
{
	for (int i = data_size - 1; i > 0; i--)
	{
		if ((lhs.value[i] >= rhs.value[i]) || (lhs.sign > rhs.sign))
		{
			return 0;
		}
	}
	return 1;
}

int operator>(const big & lhs, const big & rhs)/*broken*/
{

	for (int i = data_size - 1; i > 0; i--)
	{
		if ((lhs.value[i] <= rhs.value[i]) || (lhs.sign < rhs.sign))
		{
			return 0;
		}
	}
	return 1;
}

int operator<=(const big & lhs, const big & rhs)/*broken*/
{
	return (lhs == rhs) || (lhs < rhs);
}

int operator>=(const big & lhs, const big & rhs)/*broken*/
{
	return (lhs == rhs) || (lhs > rhs);
}



istream & operator>>(istream & lhs, big & rhs)
{
	int length;
	char *input = new char[data_size + 1];
	for (int i = 0; i < data_size; i++)
	{
		input[i] = '0';
	}
	length = strlen(input);
	lhs >> input;
	reverse(input);
	for (int i = data_size - 1; i >= 0; i--)
	{
		rhs.value[i] = ctoi(input[i]);
		if (rhs.value[i] == -2)
		{
			rhs.sign = -1;
		}
		if (rhs.value[i] < 0)
		{
			rhs.value[i] = 0;
		}
	}
	if (length < 20)
	{
		rhs.value[19] = 0;
	}
	else
	{
		rhs.value[19] = ctoi(input[19]);
	}
	return lhs;
}

ostream & operator<<(ostream & lhs, const big & rhs)
{
	if (rhs.sign < 0)
		cout << "-";
	for (int i = data_size - 1; i >= 0; i--)
	{
		lhs << rhs.value[i];
	}
	return lhs;
}

big big::operator++(int)
{
	big temp(*this);
	operator+(temp, 1);
	return temp;
}

big& big::operator++()
{
	operator+(*this, 1);
	return *this;
}

big big::operator--(int)
{
	big temp(*this);
	operator-(temp, 1);	
	return temp;
}

big& big::operator--()
{
	operator-(*this, 1);
	return *this;
}
