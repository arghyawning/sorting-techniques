#include <stdio.h>
#include <stdlib.h>

void mergeSort(int a[], int m, int b[], int n, int *arr)
{
    int i = 0, j = 0, k = 0;

    while (i < m || j < n)
    {
        if (i == m)
            arr[k++] = b[j++];
        else if (j == n)
            arr[k++] = a[i++];
        else if (a[i] <= b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
}

int main()
{
    int m, n, i, j;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &m);
    int a[m];

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);
    int b[n];

    printf("Enter the elements of the first sorted array: ");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    printf("Enter the elements of the second sorted array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int *arr = (int *)malloc((m + n) * sizeof(int));
    mergeSort(a, m, b, n, arr);

    printf("Sorted merged array is: ");
    for (i = 0; i < m + n; i++)
        printf("%d ", arr[i]);

    return 0;
}