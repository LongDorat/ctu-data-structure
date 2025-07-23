#include <stdio.h>
#include <stdlib.h>

void printArray(int nums[], int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void printState(int nums[], int numsSize, int loopTh)
{
    for (int i = 0; i < numsSize - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
        
        if (i + 1 == loopTh)
        {
            printArray(nums, numsSize);
        }
    }
}

int main()
{
    int nums1[] = {92, 38, 33, 85, 9, 98, 38, 76, 57, 71};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    
    printf("Original array:\n");
    printArray(nums1, numsSize1);
    
    printf("Sorting steps:\n");
    printState(nums1, numsSize1, 5);
    
    printf("Sorted array:\n");
    printArray(nums1, numsSize1);
    
    return 0;
}