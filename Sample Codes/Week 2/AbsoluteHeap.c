#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int compare_abs(int n1, int n2)
{
    if (abs(n1) < abs(n2)) return n1;
    else if (abs(n1) > abs(n2)) return n2;
    else return n1 < n2 ? n1 : n2;
}

void UpHeap(int *heap, int index)
{
    if (index == 1 || compare_abs(heap[index], heap[index / 2]) == heap[index / 2]) return; // Current node is bigger than parent
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
        if (compare_abs(heap[current_index * 2], heap[current_index * 2 + 1]) == heap[current_index * 2]) // Left child is smaller
        {
            if (compare_abs(heap[current_index], heap[current_index * 2]) == heap[current_index * 2])
            {
                swap(&heap[current_index], &heap[current_index * 2]);
                DownHeap(heap, current_index * 2, last_index);
            }
            else return;
        }

        else // Right child is smaller
        {
            if (compare_abs(heap[current_index], heap[current_index * 2 + 1]) == heap[current_index * 2 + 1])
            {
                swap(&heap[current_index], &heap[current_index * 2 + 1]);
                DownHeap(heap, current_index * 2 + 1, last_index);
            }
            else return;
        }
    }

    else // Has only left child
    {
        if (compare_abs(heap[current_index], heap[current_index * 2]) == heap[current_index * 2])
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