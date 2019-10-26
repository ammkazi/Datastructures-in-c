#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[10];
    int n, i, j;
    // accepting the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Storing elements in an array
    printf("Enter the numbers : \n ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Printing elements in an array
    printf("The numbers you entered are as follows : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    // Bubble Sort
    printf("Processing Bubble sort only for you. \n");

    for (i = 0; i < n; i++)
    {
        printf("Pass %d\n", i + 1);

        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }

        for (int k = 0; k < n; k++)
        {
            printf("%d\t", array[k]);
        }
        printf("\n");
    }

    printf("Array after bubble sort \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }

    // bubble sort ends
    return 0;
}