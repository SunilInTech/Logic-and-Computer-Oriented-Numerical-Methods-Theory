//Newton's Forward Difference Table

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
	printf("\n");
	
	for(i=0;i<n;i++) //entering user difined values of y
	{
		printf("y[&d]=",i);
		scanf("%f",&y[i][0]);
	}
	
	for(i=0;i<n;i++) //updating the x array
	{
		x[i+1]=x[i]+h;
	}
	
	for(j=1;j<n;j++) //updating the y array
	{
		for(i=0;i<n-j;i++)
		{
			y[i][j]=y[i+1][j-1]-y[i][j-1];
		}
	}
	
	printf("\nFORWARD DIFFERENCE TABLE\n\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("%0.1f",x[i]);
		for(j=0;j<n-i;j++)
		{
			printf("\t %0.2f",y[i][j]);
		}
	}
	getch();
}
