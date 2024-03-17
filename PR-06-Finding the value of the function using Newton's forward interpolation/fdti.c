//Newton's Forward Difference Table And Interpolation

#include<stdio.h>
void main()
{
	int n,i,j,A;
	float x[20],h,y[20][20],p,f,z,sum,p_1;
	printf("Enter the number of data point: ");
	scanf("%d",&n);
	printf("\n");
	printf("Enter the intial value: ");
	scanf("%f",&x[0]);
	printf("\n");
	printf("Enter the interval of difference: ");
	scanf("%f",&h);
	printf("\n");
	
	for(i=0;i<n;i++) //entering user difined values of y
	{
		printf("y[%d]=",i);
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
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%0.3f",x[i]);
		for(j=0;j<n-i;j++)
		{
			printf("\t %0.5f",y[i][j]);
		}
		printf("\n");
	}
	
	up:
	printf("\nEnter the interpolation point: ");
	scanf("%f",&z);
	p=(z-x[0])/h;
	p_1=p;
	f=1;
	sum=y[0][0];
	
	for(i=1;i<n;i++)
	{
		sum=sum+((p_1*y[0][i])/f);
		p_1=p_1*(p-i);
		f=f*(1+i);
	}
	printf("\ny[%0.3f]=%0.5f\n\n",z,sum);
	
	printf("Do you want to find another value? type 1 if yes: ");
	scanf("%d",&A);
	if(A==1)
	{
		goto up;
	}
	getch();
}
