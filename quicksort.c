#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median(int *a, int l, int u, int m)
{
    int arr[3] = {a[l], a[m], a[u]};

    if (a[l] == a[m])
        return m;
    else if (a[l] > a[m])
    {
        if (a[m] >= a[u])
            return m;
        else if (a[l] > a[u])
            return u;

        else
            return l;
    }
    else
    {
        if (a[m] <= a[u])
            return m;
        else if (a[l] < a[u])
            return u;
        else
            return l;
    }
}

int partition(int a[], int l, int u)
{
    int i, p = median(a, l, u, (l + u) / 2), x = l;

    for (i = l; i <= u; i++)
    {
        if (i != p && a[i] < a[p])
        {
            if (x == p)
                p = i;
            swap(&a[i], &a[x++]);
        }
    }
    swap(&a[p], &a[x]);

    return x;
}

void quickSort(int *a, int l, int u)
{
    if (l < u)
    {
        int pivot = partition(a, l, u);
        quickSort(a, l, pivot - 1);
        quickSort(a, pivot + 1, u);
    }
}

int main()
{
    int n, i, j, key, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}