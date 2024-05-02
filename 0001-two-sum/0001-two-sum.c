/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    short int    i;
    short int    j;
    int     *result;

    i = 0;
    j = 1;
    result = malloc(sizeof(int) * 2);
    if (!result)
        return (0);
    while (i < numsSize)
    {
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return (result);
            }
            j++;
        }
        i++;
        j = i + 1;
    }
    free(result);
    return (0);
}