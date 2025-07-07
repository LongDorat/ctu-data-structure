#include <stdio.h>
#include <stdlib.h>

void read_array(int n, int *nums)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
}

void shellSort(int *nums, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = nums[i];
            int j;
            for (j = i; j >= gap && nums[j - gap] > temp; j -= gap)
                nums[j] = nums[j - gap];
            nums[j] = temp;
        }
    }
}

int binarySearch(int x, int *nums, int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == x)
            return 1; // Found
        else if (nums[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0; // Not found
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *nums = (int *)malloc(sizeof(int) * n);
    int *queue = (int *)malloc(sizeof(int) * q);
    read_array(n, nums);
    read_array(q, queue);

    shellSort(nums, n);

    for (int i = 0; i < q; i++)
    {
        if (binarySearch(queue[i], nums, n) == 1)
        {
            printf("YES ");
        }
        else
        {
            printf("NO ");
        }
    }

    free(nums);
    free(queue);

    return 0;
}