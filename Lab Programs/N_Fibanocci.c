#include <stdio.h>

int Fibo(int n);

int main() 
{ 
    int n, res; 

    printf("Enter the number of terms\n");
    scanf("%d", &n); 

    if (n == 1)
        printf("Nth Fibonacci term = %d\n", n - 1);  // prints 0
    else
        res = Fibo(n); 

    printf("Nth Fibonacci term = %d\n", res);

    return 0;
}

int Fibo(int n)
{
    int a = 0, b = 1, c;

    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}