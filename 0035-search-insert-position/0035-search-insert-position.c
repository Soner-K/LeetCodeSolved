int	searchInsert(int *nums, int numsSize, int target)
{
	short int	left;

	left = 0;
    numsSize--;
	while (numsSize >= left)
	{
        if (nums[(numsSize + left) / 2] == target)
            return ((numsSize + left) / 2);
		else if (nums[(numsSize + left) / 2] < target)
			left = (numsSize + left) / 2 + 1;
		else
			numsSize = (numsSize + left) / 2 - 1;
	}
    return (left);
}