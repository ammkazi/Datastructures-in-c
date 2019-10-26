// including header files
#include <stdio.h>
// constant - the value will not change throughout the program
#define size 100

// function declaration
void merge(int arr[], int beg, int mid, int end);
void merge_sort(int a[], int, int);

int main()
{
    int arr[size];
    int i, n;

    printf("Enter the number of elements in an array : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n~~~Calling Merge Sort~~~\n");
    merge_sort(arr, 0, n - 1);

    printf("Sorted Elements in an array are as follows: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");

    return 0;
}

void merge(int arr[], int beg, int mid, int end)
{
    printf("!!!!! MERGE - Beg %d , Mid %d , End %d !!!! \n", beg, mid, end);
    int i = beg;
    int j = mid + 1;
    int index = beg;
    int temp[size];
    int k;

    while ((i <= mid) && (j <= end))
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }

    for (k = beg; k < index; k++)
    {
        arr[k] = temp[k];
    }
}
void merge_sort(int arr[], int beg, int end)
{
    printf("\nInside Merge Sort\n");
    printf("Beg = %d , End = %d\n", beg, end);
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);

        merge(arr, beg, mid, end);
    }
}
