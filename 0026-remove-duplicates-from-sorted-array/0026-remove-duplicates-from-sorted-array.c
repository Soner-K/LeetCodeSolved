int	*removeDuplicates(int *nums, int numsSize)
{
	short int	left;
	short int	i;

	left = 1;
	i = 0;
	while (i < numsSize - 1)
	{
		if (nums[i] != nums[i + 1]) 
			nums[left++] = nums[i + 1];
        if (nums[i] > nums[i + 1])
            break ;
		i++;
	}
	return (left);
}