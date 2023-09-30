#include <stdio.h>

int main ()
{
    int n, m, i, j, k;
    int a[100][100];

    printf("Input the size of the matrix NxM:\n");

    printf("rows (n) = ");
    scanf("%d", &n);

    printf("columns (m) = ");
    scanf("%d", &m);
    printf("\n\n\n");

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    i = 0;
    j = 0;
    k = 1;

    while (k <= n * m)
    {
        a[i][j] = k;

        if (i == up && j < m - right - 1)
            ++j; 

        else if (j == m - right - 1 && i < n - down - 1)
            ++i;

        else if (i == n - down - 1 && j > left)
            --j; 

        else
            --i; 

        if ((i == up + 1) && (j == left) && (left != m - right - 1))
        {
            ++up;
            ++down;
            ++right;
            ++left;
        }
        ++k;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%5d", a[i][j]);
            
        printf("\n");
    }
}
