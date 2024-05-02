int	removeElement(int *nums, int numsSize, int val)
{
	__uint8_t	i;
	__uint8_t	count;

	i = 0;
	count = 0;
	while (i < numsSize)
	{
		if (nums[i] == val)
			count++;
        else
            nums[i - count] = nums[i];
        i++;
	}
	return (numsSize - count);
}
