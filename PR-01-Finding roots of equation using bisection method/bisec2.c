//Finding the roots of equation using bisection method(Q.3)

#include<stdio.h>
#include<math.h>
#define f(x) (2*cos(x+1)+exp(x-1)-0.5)

void main()
{
	int n,i,step=0,A;
	float x[20],y[20],h,x0,x1,f0,f1,e,x2,f2;
	
	printf("Enter the number of data: \n");
	scanf("%d",&n);
	printf("Enter the intial values of x:\n");
	scanf("%f",&x[0]);
	printf("Enter the iteravel of differance: \n");
	scanf("%f",&h);
	printf("\n");
	
	printf("x\t | f(x)\n");
	for(i=0;i<n;i++)
	{
		x[i]=x[0]+i*h; //x[i+1]=x[i]+i;
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
		x2=(x0+x1)/2;
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
	    /*for(x=-4;x<=4;x*=1)
    {
        result=f(x);
        printf("%0.1f\t| %0.3f\n",x,result);
    }*/
} 
