bool isPowerOfFour(int n) {
    if (n <= 0)
        return (false);
    while (n)
    {
        if (n % 4 != 0 && n != 1)
                return (false);
        n /= 4;
    }
    return (true);
}