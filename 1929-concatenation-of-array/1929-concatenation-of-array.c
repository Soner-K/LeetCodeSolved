/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int	*getConcatenation(int *nums, int numsSize, int *returnSize)
{
	int *arr;
	short int i;

	arr = malloc(sizeof(int) * numsSize * 2);
    if (!arr)
    {
        *returnSize = 0;
        return (NULL);
    }
	i = 0;
	while (i < numsSize * 2)
	{
		if (i >= numsSize)
			arr[i] = nums[i - numsSize];
		else
			arr[i] = nums[i];
		i++;
	}
	*returnSize = numsSize * 2;
	return (arr);
}
