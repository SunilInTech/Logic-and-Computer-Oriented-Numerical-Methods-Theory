//Newton's  dividend difference table and Interpolation

#include <stdio.h>
void main() 
{
    int n, i, j,A;
    float x[20], y[20][20], xp,yp,p;
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the x values:\n");
    for (i = 0; i < n; i++) 
	{
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }
    
    printf("Enter the y values:\n");
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
    
    printf("\n-------------------------------------------------\n");
    printf("x\t y\t 1st\t 2nd\t 3rd\t 4th\t");
    printf("\n-------------------------------------------------\n");
    for (i = 0; i < n; i++) 
	{
        printf("%0.1f", x[i]);
        for (j = 0; j <n-i; j++) 
		{
            printf("\t%0.1f", y[i][j]);
        }
        printf("\n");
    }

    // Interpolation using do-while loop
    up:
        printf("\nEnter the value to interpolate (xi) or enter -1 to exit: ");
        scanf("%f", &xp);
        yp=y[0][0];
        p=1;

        for (i = 0; i < n; i++) 
		{
			p=p*(xp-x[i]);
			yp=yp+p*y[0][i+1];
		}

        printf("\nInterpolated value y[%0.2f]=%0.5f", xp,yp);
        printf("\n\nDo you wan o find another value.Type 1 f yes:");
        scanf("%d",&A);
        if(A==1)
        {
        	goto up;
		}
    getch();
}

