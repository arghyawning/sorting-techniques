#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i, j, key, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bubbleSort(a, n);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}