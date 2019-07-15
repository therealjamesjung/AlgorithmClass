#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int N, i, j, *num, tmp, min;
    scanf("%d", &N);
    num = (int*)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++) scanf("%d", &num[i]);

    for (i = 0; i < N - 1; i++) {
        min = i + 1;
        for (j = i + 2; j < N; j++) {
            if (num[j] < num[min]) {
                min = j;
            }
        }
        if (num[i] > num[min]) {
            tmp = num[i];
            num[i] = num[min];
            num[min] = tmp;
        }
    }

    for (i = 0; i < N; i++) {
        printf("%d ", num[i]);
    }
    return 0;
}