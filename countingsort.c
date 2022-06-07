#include <stdio.h>
#include <stdlib.h>

int *countingSort(int *a, int n, int k, int *freq)
{
    int i;

    for (i = 1; i < k; i++)
        freq[i] += freq[i - 1];

    int *b = (int *)malloc(n * sizeof(int));

    for (i = n - 1; i >= 0; i--)
    {
        freq[a[i]]--;
        b[freq[a[i]]] = a[i];
    }

    for (i = 0; i < n; i++)
        a[i] = b[i];

    free(b);
}

int main()
{
    int n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the upper range of the elements: ");
    scanf("%d", &k);
    k++;
    int *freq = (int *)calloc(k, sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }

    countingSort(a, n, k, freq);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}