#include <stdio.h>

int Fibo(int n);

int main() 
{ 
    int n, res; 

    printf("Enter the term: ");
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

    if (n == 1) 
        return 0;
    else if (n == 2) 
        return 1;

    else
        return (Fibo(n-1)+ Fibo(n-2));
}