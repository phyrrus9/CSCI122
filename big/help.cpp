big operator/(const big & lhs, const big & rhs)
{
	big newbie;
	char div[data_size];
	char mod[data_size];

	helper(lhs.value, rhs.value, div, mod);
	newbie.set(div, 1); //write this

	if ((lhs.sign == 1) && (rhs.sign == 1)) newbie.sign = 1;
	//do the rest
	return newbie;
}

big operator%(const big & lhs, const big & rhs)
{
	big newbie;
	char div[data_size];
	char mod[data_size];

	if (rhs == 0)
	{
		newbie = 0;
		return newbie;
	}
	
