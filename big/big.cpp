/*
 * Big number class, implementation version 1.0.0
 * this class will allow you to use up to twenty
 * digit numbers, so in stead of the +/- 2 billion
 * you get with regular c/c++ integer classes, you
 * get +/- 99999999999999999999 to work with.
 */
#include "big.h"
#include <iomanip>
using namespace std;
#include <stdio.h>
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

void helper(const int lhs[], const int rhs[], int div[], int mod[])
{
	int i;
	big temp;
	int count;
	big copy(lhs, 1);
    	int s1;
    	int s2;
	for (i = 0; i < data_size; i++)
	{
		div[i] = mod[i] = 0;
	}
    
	s1 = s2 = data_size - 1;
    
	while ((rhs[s1] == 0) && (s1 != 0))
	{	
		s1 = s1 - 1;
	}
	while ((lhs[s2] == 0) && (s2 != 0))
	{
	        s2 = s2 - 1;
	}
    
	s2 = s2 - s1;
    
	if (s2 < 0) //special case if lhs < rhs
	{
		for (i = 0; i < data_size; i++)
		{
			mod[i] = lhs[i];
		}
		return;
	}
	while (s2 >= 0)
	{
	        big hack(rhs,1);
		temp = hack;
		for (i = 0; i < s2; i++) //get it in the right spot
		{
			temp = temp * 10;
		}
		copy = copy - temp;
		count = 1;

		while (copy >= 0 && copy.sign == 1)
		{
			count++; //see how many we can pull out
			copy = copy - temp;
		}
        
		count--; //go back one so we can remove the overdeleted ammount
		div[s2] = count;
		copy = copy + temp; //put the overdeleted ammount back
		
		s2 = s2 - 1;
	}
	for (i = 0; i < data_size; i++)
	{
		mod[i] = copy.value[i];
	}
	
	return;
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
            value[x] -= 10;
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

big::big(const int *array, const int in_sign)
{
    value = new int[data_size];
    set(array, in_sign);
}

void big::set(const int array[data_size], const int in_sign)
{
    for (int i = 0; i < data_size; i++)
    {
        value[i] = array[i]; //copy the values
    }
    sign = in_sign;
}

big operator+(const big & lhs, const big & rhs)
{
	big newbie;
	int i, carry;
    //if (lhs > 1)
      //  cout << "1<0" << endl;
	if ((lhs.sign < 0) && (rhs.sign >= 0))
	{
		newbie = operator-(rhs,-lhs);
	}
	if ((rhs.sign < 0) && (lhs.sign >= 0))
	{
		newbie = operator-(lhs, -rhs);
	}
	if ((rhs.sign < 0) && (lhs.sign < 0))
	{
		newbie=-operator+(-lhs, -rhs);
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
    if (newbie >= 0)
    {
        newbie.sign = 1;
    }
	return newbie;
}

big operator-(const big & rhs)
{
	return big(rhs.value, -rhs.sign);
}

big operator-(const big & lhs, const big & rhs)/*unfinished & broken*/
{
	big newbie;
    int i, carry;
    carry = 0;
    if (lhs < 0 && rhs >= 0)
    {
        return -operator+(-lhs, rhs);
    }

// MINE
	if ((rhs < 0) && (lhs >= 0))
		{
	
		newbie = operator+(lhs, -rhs);
	
		return newbie;
		}



    if (lhs < 0 && rhs < 0)

    {
	/*
	big lhs_(lhs.value, 1);
        return operator+(rhs, lhs_);
	*/
	newbie = operator-(-rhs, -lhs);
	return newbie;
    }
    if (rhs > lhs)
    {
		newbie = - operator-(rhs, lhs);
		return newbie;
    }
    if (lhs >= 0 && rhs >= 0)
    {
        for (i = 0; i < data_size; i++)
        {
            newbie.value[i] = lhs.value[i] - rhs.value[i] + carry;
            if (newbie.value[i] < 0)
            {
                newbie.value[i] += 10;
                carry = -1;
            }
            else
            {
                carry = 0;
            }
        }
    }
	return newbie;
}

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
        else
        {
            carry = 0;
        }
      }
     }
    }
  if ((lhs.sign ==  1) && (rhs.sign ==  1)) newbie.sign = 1;
  if ((lhs.sign == -1) && (rhs.sign == -1)) newbie.sign = 1;
  if ((lhs.sign == -1) && (rhs.sign ==  1)) newbie.sign = -1;
  if ((lhs.sign ==  1) && (rhs.sign == -1)) newbie.sign = -1;


  return newbie;
}

big operator/(const big & lhs, const big & rhs)
{
	big newbie;
	int div[data_size];
	int mod[data_size];
    
    helper(lhs.value, rhs.value, div, mod);
	newbie.set(div, 1); //write this
    
	if ((lhs.sign == 1) && (rhs.sign == 1)) newbie.sign = 1;
	//do the rest*/
	return newbie;
}

big operator%(const big & lhs, const big & rhs)
{
	big newbie;
	int div[data_size];
	int mod[data_size];
    
	if (rhs == 0)
	{
		newbie = 0;
		return newbie;
	}
	
	if (rhs == 0)
    {
        newbie = 0;
    }
    helper(lhs.value, rhs.value, div, mod);
    newbie.set(mod, 1); //write this
    
	if ((lhs.sign == 1) && (rhs.sign == 1)) newbie.sign = 1;
	//do the rest*/
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
	return !(lhs==rhs);
}

int operator<(const big & lhs, const big & rhs)
{
	int i;
	if (lhs.sign < rhs.sign) return 1; // - and +
	if (lhs.sign > rhs.sign) return 0; // + and -
	if (lhs == rhs) return 0;          // Same value
	if (lhs.sign == 1)                 // + and +
	  {
	  for (i = data_size-1; i >= 0; i--)
	    {
	    if (rhs.value[i] > lhs.value[i]) return 1;
	    if (rhs.value[i] < lhs.value[i]) return 0;
	    }
	  return 0;
	  }
	                                // Both negative
	for (i = data_size -1; i>= 0;i--)
	  {
	  if (lhs.value[i] > rhs.value[i]) return 1;
	  if (lhs.value[i] < rhs.value[i]) return 0;
	  }
	return 0;
}

int operator>(const big & lhs, const big & rhs)
{
	return !((lhs < rhs) ^ (lhs == rhs));
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
		lhs << "-";
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
	temp = temp + 1;
	return temp;
}

big& big::operator++()
{
	*this = operator+(*this, 1);
	return *this;
}

big big::operator--(int)
{
	big temp(*this);
	temp = temp - 1;
	return temp;
}

big& big::operator--()
{
	*this = operator-(*this, 1);
	return *this;
}
