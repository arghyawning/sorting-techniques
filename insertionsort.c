#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, temp, p, x;
    for (i = 1; i < n; i++)
    {
        x = a[i];

        j = i - 1;
        while (j >= 0 && x < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
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

    insertionSort(a, n);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}