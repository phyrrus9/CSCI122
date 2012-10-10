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
	for (int i = 0; i < data_size; i++)
	{
		value[i] = 0;//init everything to 0 so we dont get overflows
	}
    value[0] = other;
    bool done = false;
    for (int x = 0; !done; x++)
    {
        while (value[x] > 9)
        {
            value[x] -= 10;/Users/phyrrus9/Desktop/IMG_4782.jpg
            value[x+1] ++;
        }
        if (value[x] <= 9)
        {
            done = true;
        }
    }
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
	if ((lhs < 0) && (rhs >= 0))
	{
		cout << "A-B" << endl;
		newbie = operator-(rhs,-lhs);
	}
	if ((rhs < 0) && (lhs >= 0))
	{
		cout << "B-A" << endl;
		newbie = operator-(lhs, -rhs);
	}
	if ((rhs < 0) && (lhs < 0))
	{
		cout << "-(A+B)" << endl;
		//operator+(-lhs, -rhs);
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

big operator-(const big & lhs, const big & rhs)/*unfinished & broken*/
{
	big newbie(lhs);
    int i, borrow;
    borrow = 0;
    for (i = 0; i < data_size; i++)
    {
		cout << "[-]" << lhs.value[i] << "<->" << rhs.value[i] << endl;
        if (newbie.value[i] < rhs.value[i])
		{
			cout << "gtr" << endl;
			newbie.value[i] += 10;
			newbie.value[i - 1]--;
		}
		newbie.value[i] -= rhs.value[i];
		
    }
	return newbie;
}

//big operator*(const big &lhs, const big & rhs)/*broken see note block*/
/*{
	big newbie;
	int outer, inner, carry, math = 0;
	if (lhs.sign < 0 xor rhs.sign < 0) //ONE sign
		newbie.sign = -1;
	for (outer = 0, carry = 0; outer < data_size; outer++)
	{
		for (inner = 0; inner < data_size; inner++)
		{
			math = inner + outer;
			carry = 0;
			if (math < data_size)
            {
				newbie.value[math] += rhs.value[outer] * lhs.value[inner] + carry;
				if (newbie.value[math] > 9)
				{
					carry = newbie.value[math] % 10;
					newbie.value[math] += newbie.value[math] % 10;
				}
				else
				{
					carry = 0;
				}
			}
		}
	}
	return newbie;
}*/

big operator* (const big& lhs, const big& rhs)
  {
  big newbie;
  int inner;
  int outer;
  int carry;
  const int SIZE = data_size;
  for (outer = 0; outer < SIZE; outer++)
    {
    carry = 0;
    for (inner = 0; inner < SIZE; inner++)
      {
      if (outer+inner<SIZE)
        {
        newbie.value[inner+outer] += rhs.value[outer] *
          lhs.value[inner] + carry;
        if (newbie.value[inner+outer] > 9)
          {
          carry = newbie.value[inner+outer] / 10;
          newbie.value[inner+outer] =
            newbie.value[inner+outer]%10;
          }
        else carry = 0;
        }
      }
    }
  if ((lhs.sign ==  1) && (rhs.sign ==  1)) newbie.sign = 1;
  if ((lhs.sign == -1) && (rhs.sign == -1)) newbie.sign = 1;
  if ((lhs.sign == -1) && (rhs.sign ==  1)) newbie.sign = -1;
  if ((lhs.sign ==  1) && (rhs.sign == -1)) newbie.sign = -1;


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
    if (lhs.sign != rhs.sign)
    {
        return 0;
    }
	for (int i = data_size - 1; i >= 0; i--)
	{
		if ((lhs.value[i] != rhs.value[i]))
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

int operator<(const big & lhs, const big & rhs)
{
	if (lhs.sign < 0 && rhs.sign < 0)
		return (lhs > rhs);
	for (int i = data_size - 1; i >= 0; i--)
	{
		if ((lhs.value[i] < rhs.value[i]) || (lhs.sign < rhs.sign))
		{
			return 1;
		}
	}
	return 0;
}

int operator>(const big & lhs, const big & rhs)
{
	for (int i = data_size - 1; i >= 0; i--)
	{
		if ((lhs.value[i] > rhs.value[i]) || (lhs.sign > rhs.sign))
		{
			return 1;
		}
	}
	return 0;
}

int operator<=(const big & lhs, const big & rhs)
{
	return (lhs == rhs) || (lhs < rhs);
}

int operator>=(const big & lhs, const big & rhs)
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
    bool hasprint = print_leading_zeros;
	if (rhs.sign < 0)
		cout << "-";
	for (int i = data_size - 1; i >= 0; i--)
	{
        if (rhs.value[i] != 0 || i == 0)
            hasprint = true;
        if (hasprint)
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
