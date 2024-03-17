#include <stdio.h>

int main()
{
    int n, i, j;
    char choice = 'y'; // Initialize choice to 'y' to enter the loop
    while (choice == 'y' || choice == 'Y')
    {
        printf("Enter the number of terms: ");
        scanf("%d", &n);

        float X[n], Y[n], x, sum = 0, term;

        printf("Enter values of X:\n");
        for (i = 0; i < n; i++)
        {
            printf("X[%d]: ", i);
            scanf("%f", &X[i]);
        }

        printf("Enter corresponding values of Y:\n");
        for (i = 0; i < n; i++)
        {
            printf("Y[%d]: ", i);
            scanf("%f", &Y[i]);
        }

        printf("Enter the value of x for which you want to find y: ");
        scanf("%f", &x);

        // Applying the Interpolation Formula
        for (i = 0; i < n; i++)
        {
            term = 1;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if ((X[i] - X[j]) == 0)
                    {
                        printf("Error: Division by zero\n");
                        return 1; // Exit the program with an error code
                    }
                    term = term * ((x - X[j]) / (X[i] - X[j]));
                }
            }
            sum = sum + term * Y[i];
        }

        // Output the entered values and the result of interpolation
        printf("\nEntered values:\n");
        for (i = 0; i < n; i++)
        {
            printf("X[%d] = %f, Y[%d] = %f\n", i, X[i], i, Y[i]);
        }

        printf("\nInterpolation result at X=%f is Y=%f\n", x, sum);

        printf("\nDo you want to perform another interpolation? (y/n): ");
        scanf(" %c", &choice); // Notice the space before %c to consume the newline character
    }

    return 0;
}

