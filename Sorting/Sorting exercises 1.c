#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int n;
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    shellSort(nums, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    free(nums);
    return 0;
}