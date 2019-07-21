#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


void DownHeap(int *heap, int current_index, int last_index)
{
    if (current_index * 2 > last_index) return; // Leaf node

    else if (current_index * 2 < last_index) // Has both child nodes
    {
        if (heap[current_index * 2] < heap[current_index * 2 + 1]) // Left child is smaller
        {
            if (heap[current_index] > heap[current_index * 2])
            {
                swap(&heap[current_index], &heap[current_index * 2]);
                DownHeap(heap, current_index * 2, last_index);
            }
            else return;
        }
        else // Right child is smaller
        {
            if (heap[current_index] > heap[current_index * 2 + 1])
            {
                swap(&heap[current_index], &heap[current_index * 2 + 1]);
                DownHeap(heap, current_index * 2 + 1, last_index);
            }
            else return;
        }
    }

    else // Has only left child
    {
        if (heap[current_index] > heap[current_index * 2])
        {
            swap(&heap[current_index], &heap[current_index * 2]);
            DownHeap(heap, current_index * 2, last_index);
        }
        else return;
    }
}

int main(){
    int *heap;
    int n, i, index;

    scanf("%d", &n);

    heap = (int *)malloc(sizeof(int) * (n + 1));

    for (i = 1; i <= n; i++) scanf("%d", &heap[i]);

    for (i = n / 2; i >= 1; i--) DownHeap(heap, i, n);

    index = n;
    for (i = 1; i <= n; i++)
    {
        printf("%d\n", heap[1]);
        heap[1] = heap[index--];
        DownHeap(heap, 1, index);
    }

    return 0;
}