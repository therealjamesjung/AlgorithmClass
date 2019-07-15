#include <stdio.h>

int power(int A, int B)
{
    int tmp;

    if (B == 0) return 1;

    tmp = power(A, B / 2);

    if (B % 2 == 0) return tmp * tmp;
    else return A * tmp * tmp;
}

int main()
{
    int A, B;
    int answer = 1;

    scanf("%d", &A);
    scanf("%d", &B);


    answer = power(A, B);
    printf("%d", answer);
    return 0;
}