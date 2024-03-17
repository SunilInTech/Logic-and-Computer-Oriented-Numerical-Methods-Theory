/* Program: Finding real roots of nonlinear equation using Newton Raphson Method*/ 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* Defining equation to be solved. Change this equation to solve another problem. */
#define    f(x)  x*cos(x)+1

/* Defining derivative of g(x). As you change f(x), change this function also. */
#define   g(x)  -x*sin(x)+cos x

void main()
{
	float x0, x1, f0, f1, g0, e;
	int step = 1, A;
    /* Inputs */
	up:
	printf("\nEnter initial guess:\n");
	scanf("%f", &x0);
	printf("Enter tolerable error:\n");
	scanf("%f", &e);

	/* Implementing Newton Raphson Method */
	printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	do
	{
		f0 = f(x0);
		g0 = g(x0);
		if(g0 == 0.0)
		{
			printf("Mathematical Error.");
			goto up;
		}
		x1 = x0 - f0/g0;
		printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,x1,f1);
		x0 = x1;
		step = step+1;
	}while(fabs(f1)>e);
	
	printf("\nRoot is: %f", x1);
	printf("\n\nDo you want to find another rrot? If YES Type 1: ");
	scanf("%d",&A);
	if(A===1)
	{
		goto up;
	}
	getch();
}
