//Finding roots of equation using secant method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) exp(-x)-tan(x)

void main()
{
    float x0,x1,f0,f1,e,x2,f2;
    int A,i;
up:
    printf("Enter the value of x0 and x1: \n");
    scanf("%f %f",&x0,&x1);

    printf("Enter the tolerable error, e: ");
    scanf("%f",&e);

    printf("\n\nn\t x \t\t f(x)\n");
    printf("0 \t %0.4f\t\t %0.4f\n",x0,f(x0));
    printf("1 \t %0.4f\t\t %0.4f\n",x1,f(x1));

    i=2;
    do{
        f0=f(x0);
        f1=f(x1);
        x2=x1-(x1-x0)*f1/(f1-f0);
        f2=f(x2);
        printf("%d \t %0.4f\t\t %0.4f\n",i,x2,f2);
        x0=x1;
        x1=x2;
        i++;
    }while(fabs(f2)>e);
    printf("\nThe required root is %0.4f\n",x2);
    printf("Do you want to find another root? If yes, type 1: ");
    scanf("%d",&A);
    if(A==1)
    {
        goto up;
    }
}
