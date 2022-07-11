#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3000000

void sort(int end[], int start[], int len)
{
    int i, j, tmp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (end[j] > end[j + 1])
            {
                tmp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = tmp;
                tmp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = tmp;
            }
        }
    }
}

int partition(int arr[], int withArr[], int low, int high)
{
    int key, tmp;
    key = arr[low];
    tmp = withArr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= key)
            high--;
        if (low < high)
        {
            withArr[low] = withArr[high];
            arr[low++] = arr[high];
        }
        while (low < high && arr[low] <= key)
            low++;
        if (low < high)
        {
            withArr[high] = withArr[low];
            arr[high--] = arr[low];
        }
    }
    arr[low] = key;
    withArr[low] = tmp;
    return low;
}
void quick_sort(int arr[], int withArr[], int start, int end)
{
    int pos;
    if (start < end)
    {
        pos = partition(arr, withArr, start, end);
        quick_sort(arr, withArr, start, pos - 1);
        quick_sort(arr, withArr, pos + 1, end);
    }
    return;
}

int main()
{
    int n, m, h, b, q = 0, p = 0, count = 1, endTime;
    scanf("%d", &n);
    int end[n], start[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &start[i], &end[i]);
    }
    quick_sort(end, start, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d %d;", start[i], end[i]);
    // }

    endTime = end[0];
    for (int i = 1; i < n; i++)
    {
        if (start[i] >= endTime)
        {
            count++;
            endTime = end[i];
        }
    }
    printf("%d", count);
}