#include <stdio.h>
#include <stdlib.h>

const int base = 10;

int max(int *a, int n)
{
    int i, m = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
    }
    return m;
}

int *countingSort(int *a, int n, int k)
{
    int i, x;
    int *freq = (int *)calloc(base, sizeof(int));

    for (i = 0; i < n; i++)
    {
        x = (a[i] / k) % base;
        freq[x]++;
    }

    for (i = 1; i < base; i++)
        freq[i] += freq[i - 1];

    int *b = (int *)malloc(n * sizeof(int));

    for (i = n - 1; i >= 0; i--)
    {
        x = (a[i] / k) % base;
        freq[x]--;
        b[freq[x]] = a[i];
    }

    for (i = 0; i < n; i++)
        a[i] = b[i];

    free(b);
}

int radixSort(int *a, int n)
{
    int m = max(a, n), k = 1;

    while (m > 0)
    {
        countingSort(a, n, k);

        m /= base;
        k *= base;
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

    radixSort(a, n);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);

    return 0;
}