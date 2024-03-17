//Newton's  dividend difference table

#include <stdio.h>
void main() 
{
    int n, i, j;
    float x[20], y[20][20];
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the x values:\n");
    for (i = 0; i < n; i++) 
	{
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }
    
    printf("Enter the  values:\n");
    for (i = 0; i < n; i++) 
	{
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    // Calculate the Dividend Difference Table
    for (i = 1; i < n; i++) 
	{
        for (j = 0; j < n - i; j++) 
		{
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);
        }
    }

    // Display the Dividend Difference Table
    printf("\nNewton's Dividend Difference Table:\n");
    for (i = 0; i < n; i++) 
	{
        printf("%0.1f", x[i]);
        for (j = 0; j <n-i; j++) 
		{
            printf("\t%0.1f", y[i][j]);
        }
        printf("\n");
    }

    getch();
}

