int strStr(char* haystack, char* needle) 
{
    short int i;
    short int j;

    i = 0;
    j = 0;
    while (haystack[i])
    {
        while (haystack[i + j] == needle[j])
        {
            if (!needle[j + 1])
                return (i);
            j++;
        }
        j = 0;
        i++;
    }
    return (-1);
}