//Finding roots of equation using False Position Method(Q.2)
#include <stdio.h>
#include <math.h>
#define f(x) (pow(x,2)*asin(x/5)-5*x+3)
void main()
{
    int step=0,A;
    float x0,x1,f0,f1,e,x2,f2;

    up:
    printf("Enter the initial guesses(x0 and x1): ");
    scanf("%f%f",&x0,&x1);
    f0=f(x0);
    f1=f(x1);
    if(f0*f1>0)
    {
        printf("\nIncorrect Initial Guesses!");
        goto up;
    }

    printf("Enter the tollearble error,E:");
    scanf("%f",&e);
	do{
		x2=(x0*f1-x1*f0)/(f1-f0);
		f2=f(x2);
		
		printf("%d\t%0.3f\t%0.3f\t%0.3f\t%0.3f\n",step,x0,x1,x2,f2);
		
		if(f0*f2<0)
		{
			x1=x2;
			f1=f2;
		}
		else
		{
			x0=x2;
			f0=f2;
		}
		step=step+1;
		
	}while (fabs(f2) > e);
	
	printf("root of %0.5f ",x2);
	
	printf("\n\nDo you want to find another ROOT? Type 1 if yes: ");
	scanf("%d",&A);
	if(A==1)
	{
		goto up;
	}
	getch();
} 