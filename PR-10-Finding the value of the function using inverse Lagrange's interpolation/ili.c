//Lagrange's Inverse of Interpolation

#include <stdio.h>
void main()
{
    int n,i,j,A;
    float x[20],y[20],xp,yp,p;

    printf("Enter the number of data points: ");
    scanf("%d",&n);
    printf("\n");

    printf("Enter the values of x array: \n");
    for(i=0; i<n; i++)
    {
        printf("x[%d]=",i);
        scanf("%f",&x[i]);
    }
    printf("\n");

    printf("Enter the values of y array: \n");
    for(i=0; i<n; i++)
    {
        printf("y[%d]=",i);
        scanf("%f",&y[i]);
    }
    printf("\n");

    printf("x \t y\n");
    for(i=0; i<n; i++)//printing the given table
    {
        printf("%0.3f",x[i]);
        printf("\t%0.6f",y[i]);
        printf("\n");
    }

up:
    printf("Enter the interpolation point: ");
    scanf("%f",&xp);
    yp=0;
    for(i=0; i<n; i++)
    {
        p=1;
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                p=p*(xp-x[j])/(x[i]-x[j]);
            }
        }
        yp=yp+(p*y[i]);
    }
    printf("y[%0.3f]=%0.6f",xp,yp);

    printf("\n\nDo you want to find another value? Type 1 if yes: ");
    scanf("%d",&A);
    if(A==1)
    {
        goto up;
    }
}
