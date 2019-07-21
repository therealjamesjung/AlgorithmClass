#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void UpHeap(int *heap, int index)
{
    if (index == 1 || (heap[index / 2] > heap[index])) return;
    else
    {
        swap(&heap[index], &heap[index / 2]);
        UpHeap(heap, index / 2);
    }
}

void DownHeap(int *heap, int current_index, int last_index)
{
    if (current_index * 2 > last_index) return; // Leaf node

    else if (current_index * 2 < last_index) // Has both child nodes
    {
        if (heap[current_index * 2] > heap[current_index * 2 + 1]) // Left child is bigger
        {
            if (heap[current_index] < heap[current_index * 2])
            {
                swap(&heap[current_index], &heap[current_index * 2]);
                DownHeap(heap, current_index * 2, last_index);
            }
            else return;
        }
        else // Right child is bigger
        {
            if (heap[current_index] < heap[current_index * 2 + 1])
            {
                swap(&heap[current_index], &heap[current_index * 2 + 1]);
                DownHeap(heap, current_index * 2 + 1, last_index);
            }
            else return;
        }
    }

    else // Has only left child
    {
        if (heap[current_index] < heap[current_index * 2])
        {
            swap(&heap[current_index], &heap[current_index * 2]);
            DownHeap(heap, current_index * 2, last_index);
        }
        else return;
    }
}

int main(){
    int *heap;
    int n, i, num;
    int index = 1;

    scanf("%d", &n);

    heap = (int *)malloc(sizeof(int) * (n + 1));

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &num);

        if (num == 0)
        {
            if (index == 1)
            {
                printf("0\n");
                continue;
            }
            printf("%d\n", heap[1]);
            heap[1] = heap[--index];
            DownHeap(heap, 1, index);
        }
        else
        {
            heap[index] = num;
            UpHeap(heap, index++);
        }
    }

    return 0;
}