#include <stdio.h>
#include <stdlib.h>

void printArray(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void bubbleSort(int *nums, int numsSize)
{
    for (int i = 1; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
        printArray(nums, numsSize);
    }
}

void selectionSort(int *nums, int numsSize)
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
        printArray(nums, numsSize);
    }
}

void insertionSort(int *nums, int numsSize)
{
    for (int i = 1; i < numsSize; i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
        printArray(nums, numsSize);
    }
}

int main()
{
    int nums1[] = {92, 38, 33, 85, 9, 98, 38, 76, 57, 71};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);

    printf("Original array:\n");
    printArray(nums1, numsSize1);

    printf("Sorting steps:\n");
    selectionSort(nums1, numsSize1);

    printf("Sorted array:\n");
    printArray(nums1, numsSize1);

    int nums2[] = {24, 18, 37, 60, 61, 28, 6, 46, 39, 84};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("\nOriginal array:\n");
    printArray(nums2, numsSize2);

    printf("Sorting steps:\n");
    bubbleSort(nums2, numsSize2);

    printf("Sorted array:\n");
    printArray(nums2, numsSize2);

    int nums3[] = {88, 75, 44, 49, 8, 95, 71, 24, 79, 92};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("\nOriginal array:\n");
    printArray(nums3, numsSize3);

    printf("Sorting steps:\n");
    insertionSort(nums3, numsSize3);

    printf("Sorted array:\n");
    printArray(nums3, numsSize3);

    return 0;
}