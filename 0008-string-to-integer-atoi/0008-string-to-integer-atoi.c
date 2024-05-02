#include <stddef.h>
#include <string.h>

int myAtoi(char* s) {
    long	    num;
	char        sign;

	num = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || (*s == 32))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	} 
    while (*s && *s == '0')
        s++;
	while (*s >= '0' && *s <= '9')
	{
        if (strlen(&*s) > 18)
        {
            if (sign == 1)
                return (INT_MAX);
            else
                return (INT_MIN);
        }
		num *= 10;
		num += (*s - '0');
		s++;
        if (*s < '0' && *s > '9')
            return (num * sign);
	}
	num *= sign;
    if (num > INT_MAX)
        return (INT_MAX);
    if (num < INT_MIN)
        return (INT_MIN);
    return (num);
}