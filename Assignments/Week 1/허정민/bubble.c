#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int N, i, j, *num, tmp;
    scanf("%d", &N);
    num = (int*)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (num[j] > num[j+1]) {
                tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d ", num[i]);
    }
    return 0;
}