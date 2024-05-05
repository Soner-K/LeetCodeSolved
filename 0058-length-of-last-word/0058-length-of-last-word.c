char	only_space(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

int	lengthOfLastWord(char *s)
{
	short int	len;

	len = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			len++;
			s++;
			if (only_space(s))
				return (len);
		}
		else
		{
			len = 0;
			s++;
		}
	}
	return (len);
}