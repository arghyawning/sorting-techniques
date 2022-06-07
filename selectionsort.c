#include <stdio.h>

void selectionSort(int a[], int n)
{
    int i, j, p, temp;

    for (i = 0; i < n; i++)
    {
        p = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[p])
                p = j;
        }

        temp = a[i];
        a[i] = a[p];
        a[p] = temp;
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

    selectionSort(a, n);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}