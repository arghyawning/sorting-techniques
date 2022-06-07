#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void merge(int a[], int l, int m, int u)
{
    int i = l, j = m + 1, k = 0;

    int *b = (int *)malloc((u - l + 1) * sizeof(int));

    while (i <= m || j <= u)
    {
        if (i > m)
            b[k++] = a[j++];
        else if (j > u)
            b[k++] = a[i++];
        else if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    for (i = l; i <= u; i++)
        a[i] = b[i - l];

    free(b);
}

void mergeSort(int *a, int l, int u)
{
    int m;
    if (l < u)
    {
        m = (l + u) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, u);
        merge(a, l, m, u);
    }
}

int main()
{
    int n, i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);

    return 0;
}