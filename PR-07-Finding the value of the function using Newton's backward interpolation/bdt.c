//Newton's Backward Difference Table

#include<stdio.h>
void main()
{
	int n,i,j;
	float x[20],h,y[20][20];
	printf("Enter the number of data point: ");
	scanf("%d",&n);
	printf("Enter the intial value: ");
	scanf("%f",&x[0]);
	printf("Enter the interval of difference: ");
	scanf("%f",&h);
	
	for(i=0;i<n;i++)
	{
		printf("y[%d]=", i);
        scanf("%f", &y[i][0]);
	}
	
	for(i=0;i<n;i++) //updating the x array
	{
		x[i+1]=x[i]+h;
	}
	
    // Generating Backward Difference Table //
	for(i = 1; i < n; i++)
	{
		for(j = n-1; j > i-1; j--)
		{
			y[j][i] = y[j][i-1] - y[j-1][i-1];
		}
	}
	
	printf("\nBACKWARD DIFFERENCE TABLE\n\n");
    for(i = 0; i < n; i++)
    {
    	printf("%0.2f", x[i]);
    	for(j = 0; j <= i ; j++)
    	{
    		printf("\t%0.2f", y[i][j]);
		}
		printf("\n");
	}
	getch();
}
