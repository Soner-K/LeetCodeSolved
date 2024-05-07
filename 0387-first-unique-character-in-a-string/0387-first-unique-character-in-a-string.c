int	firstUniqChar(char *s)
{
    int   tab[26] = {0};
    int   i = -1;

    while (s[++i])
        tab[(s[i] - 'a')]++;
    i = -1;
    while (s[++i])
    {
        if (tab[(s[i] - 'a')] == 1)
            return (i);
    }
    return (-1);
}         