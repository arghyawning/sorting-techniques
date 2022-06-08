#include <stdio.h>
#include <stdlib.h>

typedef struct Heap *heap;

struct Heap
{
    int size;
    int *a;
};

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void adjustHeap(heap h, int i, int n)
{
    int maxchild;
    while (left(i) < n)
    {
        maxchild = left(i);

        if (right(i) < n && h->a[right(i)] > h->a[maxchild])
            maxchild = right(i);

        if (h->a[i] >= h->a[maxchild])
            break;

        swap(&h->a[i], &h->a[maxchild]);
        i = maxchild;
    }
}

void ensureHeap(heap h)
{
    int i;

    for (i = h->size / 2 - 1; i >= 0; i--)
        adjustHeap(h, i, h->size);
}

void heapSort(heap h)
{
    int n = h->size;

    while (n > 0)
    {
        swap(&h->a[0], &h->a[n - 1]);
        n--;
        adjustHeap(h, 0, n);
    }
}

int main()
{
    int i;

    heap h;
    h = (heap)malloc(sizeof(struct Heap));

    printf("Enter the number of elements: ");
    scanf("%d", &h->size);

    h->a = (int *)malloc(sizeof(int) * h->size);

    printf("Enter the elements: ");
    for (i = 0; i < h->size; i++)
        scanf("%d", &h->a[i]);

    ensureHeap(h);

    heapSort(h);

    for (i = 0; i < h->size; i++)
        printf("%d ", h->a[i]);
    printf("\n");

    return 0;
}
