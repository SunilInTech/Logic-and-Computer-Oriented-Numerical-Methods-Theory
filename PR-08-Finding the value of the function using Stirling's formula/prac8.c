//Finding the value of the function using Stirling's formula

#include<stdio.h> 
#include<math.h>
int main()
{
    float x[20], y[20][20], h, fx, fy, p, p1, p2, E, O; 
    int n, i, j, s, f, f1, A;
    printf("\t STIRLING'S INTERPOLATION \n");

    /* Input Section */
    printf("Enter number of data? "); 
    scanf("%d", &n);
    printf("Enter the initial x value (x0): "); 
    scanf("%f", &x[0]);
    printf("Enter the interval of differencing(h): "); 
    scanf("%f", &h);
    for(i=0; i<n;i++)
    {
        x[i+1]=x[i]+h;
    }
    printf("Enter the y values: \n"); 
    for(i = 0; i < n ; i++)
    {
        printf("y[%d]=", i);
        scanf("%f", &y[i][0]);
    }
    /* Generating Forward Difference Table */ 
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < n-i; j++)
        {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
    }

    /* Displaying Forward Difference Table */ 
    printf("\nFORWARD DIFFERENCE TABLE\n\n"); 
    for(i = 0; i < n; i++)
    {
        printf("%0.1f", x[i]); 
        for(j = 0; j < n-i ; j++)
        {
            printf("\t%0.1f", y[i][j]);
        }
        printf("\n");
    }
    up:
    printf("\nEnter the value of x for which you want to find y: "); 
    scanf("%f",&fx);
    s = floor(n/2);
    printf("x[%d] = %0.1f\ty[%d] = %0.2f \n\n", s, x[s], s, y[s][0]); 
    p = (fx-x[s])/h;
    O = 0;
    E = 0;
    p1=p; 
    p2=p*p; 
    f=1;
    f1=1;
    /*APPLYING STIRLING'S FORMULA*/
    for(i=1;i<s;i++)
    {
        O=O+p1*(y[s-i+1][2*i-1]+y[s-i][2*i-1])/(2*f); 
        p1=p1*(p*p-i*i);
        f=f*2*i*(2*i+1);
    }
    printf("\n\n"); 
    for(i=1;i<s;i++)
    {
        E=E+p2*y[s-i][2*i]/(2*f1*i); 
        p2=p2*(p*p-i*i);
        f1=f1*2*i*(2*i+1);
    }
    fy=y[s][0]+E+O;
    printf("\n y(%0.3f) = %0.5f",fx,fy);
    /* If another root is to be found */
    printf("\n\nDo you want to find another root? (Y=1/N=0): "); 
    scanf("%d", &A);
    if( A==1)
    {
        goto up;
    }
    return 0;
}
