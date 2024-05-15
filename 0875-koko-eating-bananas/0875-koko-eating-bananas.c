int8_t  check(int *piles, int pilesSize, int k, int h)
{
    int count = 0;

    if (k == 0)
        return (false);
    for (short int i = 0; i < pilesSize; i++)
    {
        if (count > h)
            return  (false);
        count += (piles[i] / k) + (piles[i] % k != 0);
    }
    return (count <= h ? true : false);
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int k = 0;
    int left = 1;
    int right = 0;
    for (short int i; i < pilesSize; i++)
    {
        if (piles[i] > k)
            k = piles[i];
    }
    if (pilesSize == h)
        return (k);
    right = k;
    while (left <= right)
    {
        k = left + (right - left) / 2;
        if (check(piles, pilesSize, k, h))
            right = k - 1;
        else
            left = k + 1;
    }
    return (check(piles, pilesSize, k, h) == true ? k : k + 1);
}      