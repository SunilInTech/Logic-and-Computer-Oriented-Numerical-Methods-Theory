/* Program: Finding real roots of nonlinear equation using Fixed Point Iteration*/

#include<stdio.h>
#include<math.h>

/* Define function f(x) which is to be solved */
#define   f(x)   pow(x,2)-3*x+1
/* Write f(x) as x = g(x) and define g1(x) and g2(x) here */
#define   g1(x)   (pow(x,2)+1)3
#define   g2(x)   3-(1/x)

void main()
{
	int step=1, A,B;
	float x0, x1, e;

	printf("g1=(x^2+1)3 \n g2=3-(1/x): \n");
	/* Inputs */
	up:
	printf("Which function you want to use g1=1 / g2=2 : \n");
	sacnf("%d",&B);
	printf("Enter initial guess(x0): ");
	scanf("%f", &x0);
	printf("Enter tolerable error: ");
	scanf("%f", &e);
	/* Implementing Fixed Point Iteration */
	printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	do
	{
		if(B==1)
		{
			x1=g1(x0);
		}
		else{
			x1=g2(x0);
		}
		printf("%d\t%f\t%f\t%f\t%f\n",step, x0, f(x0), x1, f(x1));
		
		step++; 
		x0 = x1;
		  
	}while( fabs(f(x1)) > e);
	 
	printf("\nRoot is %f", x1);
	printf("\n\nDo you want to another Root? if yes type 1 : \n");
	scanf("%d",&A);
	if(A==1)
	{
		goto up;
	}
	getch();
}
