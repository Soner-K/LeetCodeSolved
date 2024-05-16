void    helper(char *s, int start, int end)
{
    if (start >= end)
        return ;
    char    tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
    helper(s, start + 1, end - 1);
}

void reverseString(char* s, int sSize) {
    helper(s, 0, sSize - 1);
}