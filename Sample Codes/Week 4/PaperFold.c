#include <stdio.h>
#include <stdlib.h>

int result[2] = {0};

int check(int **grid, int x, int y, int length)
{
    int i, j;
    int flag = grid[x][y];

    for (i = x; i < x + length; i++) for (j = y; j < y + length; j++) if (flag != grid[i][j]) return -1;

    return flag;
}

void divide(int **grid, int x, int y, int length, int depth)
{
    int flag;
    if (length == 0) return;
    flag = check(grid, x, y, length);

    if (flag == -1)
    {
        divide(grid, x, y, length/2, depth);
        divide(grid, x + length/2, y, length/2, depth);
        divide(grid, x, y + length/2, length/2, depth);
        divide(grid, x + length/2, y + length/2, length/2, depth);
    }
    else if (flag == 0) result[0]++;
    else if (flag == 1) result[1]++;
}

int main()
{
    int **grid;
    int n, i, j;

    scanf("%d", &n);

    grid = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++) grid[i] = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d",&grid[i][j]);

    divide(grid, 0, 0, n, 0);

    printf("%d\n%d", result[0], result[1]);

    return 0;
}