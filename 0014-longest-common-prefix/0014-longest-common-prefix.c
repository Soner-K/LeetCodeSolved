#include <stdint.h>
#include <string.h>

void	move_shortest(char **strs, int strsSize)
{
	char	*tmp;
	int8_t	i;
	int8_t	min_index;

	i = 1;
	min_index = 0;
	while (--strsSize)
	{
		if (strlen(strs[min_index]) > (int8_t)strlen(strs[i]))
			min_index = i;
		i++;
	}
	tmp = strs[0];
	strs[0] = strs[min_index];
	strs[min_index] = tmp;
}  

char	*longestCommonPrefix(char **strs, int strsSize)
{
	int8_t	i;
	int8_t	j;

	i = 1;
	j = 0;
	move_shortest(strs, strsSize);
	while (--strsSize)
	{
		while (strs[0][j] && strs[0][j] == strs[i][j])
			j++;
		strs[0][j] = '\0';
		i++;
		j = 0;
	}
	return (strs[0]);
}