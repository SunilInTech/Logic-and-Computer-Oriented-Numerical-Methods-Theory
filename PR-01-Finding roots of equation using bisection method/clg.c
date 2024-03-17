//Finding the roots of equation using bisection method(Q.2)
#include<stdio.h>
#include<math.h>
#define cos(x)+pow(x,2)-5
void main()
{
    float x0,x1,f0,f1,e,x2,f2;
    int step=0,A;
    
    up:
    printf("Enter the intial guesses\n",x0,x1);
    scanf("%f %f",&x0,&x1);
    f0=f(x0);
    f1=f(x1);
    
    if(f0*f1>0)
    {
        printf("Inorrect intial guesses\n\n");
        goto up;
    }
    
    printf("enter the tollarable error e=\n");
    scanf("%f",&e);
    
    do{
        x2=(x0+x1)/2;
        f2=f(x2);
        
        printf("%d\t %0.4f\t %0.4f\t %0.4f\t %0.4f\n",step,x0,x1,x2,f2);
        
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
    }while(fabs(f2)>e);
    
    printf("root of %0.3f ",x2);
    
    printf("\n\nDo you want to find another ROOT? Type 1 if yes: ");
    scanf("%d",&A);
    if(A==1)
    {
        goto up;
    }
    
    getch();
}

