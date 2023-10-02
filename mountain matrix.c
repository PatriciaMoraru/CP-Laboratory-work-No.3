#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generator_matrix(int arr[][100], int max, int n, int m)
{
	int i, j;
	
	for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
        	arr[i][j] = (rand() % max) + 1;
		}
    }    
    return;
}

void convert_2D_to_1D(int arr2[][100], int n, int m, int b[])
{
    int x = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[x] = arr2[i][j];
            x++;
        }
    }
}

void bubble_sort(int x[], int n, int m)
{
    int j, aux;
    int k = n * m;

    for (int i = 0; i < k-1; i++)
    {
        for (j = 0; j < k-i-1; j++)
        {
            if (x[j] > x[j+1])
            {
                aux = x[j+1];
                x[j+1] = x[j];
                x[j] = aux;
            }
        }
    }
}

int main ()
{
    int n, m, i, j, k;
    int a[100][100];
    int a1[1000];
    int a2[100][100];
    
    srand(time(NULL));

    printf("Input the size of the matrix NxM:\n");

    printf("rows (n) = ");
    scanf("%d", &n);

    printf("columns (m) = ");
    scanf("%d", &m);
    printf("\n\n\n");
    
    generator_matrix(a, 1000, n, m);
    printf("The generated unsorted matrix: \n");
	
	for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%5d", a[i][j]);
            
        printf("\n");
    }
    
    convert_2D_to_1D(a, n, m, a1);
    bubble_sort(a1, n, m);

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    i = 0;
    j = 0;
    k = 0;  

    while (k < n * m)
    {
        a2[i][j] = a1[k];

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
	
	printf("\n The Sorted Matrix in a Spiral: \n");
	
	
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%5d", a2[i][j]);
            
        printf("\n");
    }
}
