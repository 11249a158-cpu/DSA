--->AIM:- Fibonacci series using Recursion


--->Program:-

#include<stdio.h>   // Standard input-output header file

// Function to calculate nth Fibonacci number using recursion
int fib(int n)
{
    // Base case: if n is 0, return 0
    if(n==0)
    return 0;
    
    // Base case: if n is 1, return 1
    if(n==1)
    return 1;
    
    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n,result;   // Declaration of variables
    
    // Prompt user to enter a value
    printf("Enter a value for n:");
    scanf("%d",&n);  // Read input from user
    
    // Check for negative input
    if(n<0)
    {
        printf("Invalid number!");  // Display error message
        return 0;   // Exit the program
    }
    
    result=fib(n);  // Call fibonacci function
    
    // Display the nth Fibonacci term
    printf("nth fibonacci term is %d\n",result);
    
    return 0;   // Indicate successful program termination
}
