//Finding roots of equation using False Position Method(Q.1)
#include <stdio.h>
#include <math.h>
#define f(x) (5*x*log10(x+10)-2*pow(x,2)+20)
void main()
{
    int n,i,step=0,A;
    float x[20],y[20],h,x0,x1,f0,f1,e,x2,f2;

    printf("Enter the number of data: ");
    scanf("%d",&n);
    printf("Enter the inittial vale of x:");
    scanf("%f",&x[0]);
    printf("Enter the iteraval of differance: ");
    scanf("%f",&x[0]);

    printf("\n");
    printf("x\t|f(x)\n");
    prinft("----------------------");

    for(i=0;i<n;i++)
    {
        x[i]=x[0]+i*h; //x[i+1]=x[i]+1;
        y[i]=f(x[i]);
    }

    for(i=0;i<n;i++)
	{
		printf("%0.1f\t %0.3f\n",x[i],y[i]);
	}
	printf("\n\n");
	
	up:
	printf("Enter the initial guesses: \n");
	scanf("%f%f",&x0,&x1);
	f0=f(x0);
	f1=f(x1);
	if(f0*f1>0)
	{
		printf("Incorrect inital gusesses.\n\n");
		goto up;
	}
	
	printf("Enter the tollerable error,E: \n");
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