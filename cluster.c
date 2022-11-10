#include <stdio.h>
#include <stdlib.h>
int mean(int arr[], int n)
{
    int i, mean, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    mean = sum / n;
}
int small(int a, int b, int c, int d)
{
    if ((a < b) && (b < c) && (c < d))
    {
        return a;
    }
    else if ((d < c) && (c < b) && (b < a))
    {
        return d;
    }
    else if ((c < d || c < a) && (a < d || d < a) && (a < b || d < b))
    {
        return c;
    }
    else if ((b < a || b < d) && (a < d || d < a) && (d < c || a < c))
    {
        return b;
    }
}
int main()
{
    int n, a, b, c, d, o, i, j, g1, g2, g3, g4,lower,upper;
    printf("Enter the seed values: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("Enter the no of elemnts in the array: ");
    scanf("%d", &n);
    printf("Enter the upper and lower limit of the range: ");
    scanf("%d%d", &lower,&upper);
    g1 = a, g2 = b, g3 = c = c, g4 = d;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
    for (j = 0; j < n / 2; j++)
    {
        int *s1 = (int *)malloc(n * sizeof(int)), *s2 = (int *)malloc(n * sizeof(int)), *s3 = (int *)malloc(n * sizeof(int)), *s4 = (int *)malloc(n * sizeof(int));
        for (o = 0; o < n; o++)
        {
            s1[o] = 0;
            s2[o] = 0;
            s3[o] = 0;
            s4[o] = 0;
        }
        s1[0] = g1, s2[0] = g2, s3[0] = g3, s4[0] = g4;
        for (i = 0; i < n; i++)
        {
            int A, B, C, D, m, k, l=n;
            A = abs(a - arr[i]), B = abs(b - arr[i]), C = abs(c - arr[i]), D = abs(d - arr[i]);
            m = small(A, B, C, D);
            if (m == A)
            {
                s1[i + 1] = arr[i];
                // l = sizeof(s1) / sizeof(s1[0]);
                k = mean(s1, l);
                s1[0] = k;
            }
            else if (m == B)
            {
                s2[i + 1] = arr[i];
                // l = sizeof(s2) / sizeof(s2[0]);
                k = mean(s2, l);
                s2[0] = k;
            }
            else if (m == C)
            {
                s3[i + 1] = arr[i];
                // l = sizeof(s3) / sizeof(s3[0]);
                k = mean(s3, l);
                s3[0] = k;
            }
            else if (m == D)
            {
                s4[i + 1] = arr[i];
                // l = sizeof(s4) / sizeof(s4[0]);
                k = mean(s4, l);
                s4[0] = k;
            }
            g1 = s1[0], g2 = s2[0], g3 = s3[0], g4 = s3[0];
            free(s1);
            free(s2);
            free(s3);
            free(s4);
        }
    }
    printf("The means are s1=%d, s2=%d, s3=%d,s4=%d", g1, g2, g3, g4);
}
