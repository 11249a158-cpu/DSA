-->AIM:-Implementation of Tower Of Hanoi(TOH) using Recursive Function


-->Program:-

#include<stdio.h>   // Header file for input/output functions

// Function to solve Tower of Hanoi problem using recursion
// n  -> number of disks
// S  -> source rod
// T  -> temporary (auxiliary) rod
// D  -> destination rod
void TOH(int n, char S, char T, char D)
{
    // Base condition: if only one disk is present
    if(n == 1)
    {
        // Move the single disk directly from source to destination
        printf("Move %d from %c to %c\n", n, S, D);
        return;   // Stop further recursion
    }
    
    // Step 1: Move top (n-1) disks from source to temporary rod
    TOH(n-1, S, T, D);
    
    // Step 2: Move the nth (largest) disk from source to destination
    printf("Move %d from %c to %c\n", n, S, D);
    
    // Step 3: Move the (n-1) disks from temporary rod to destination
    TOH(n-1, T, D, S);
}

int main()
{
    int n;          // Variable to store number of disks
    char S, T, D;   // Rod names (not used for input, only symbolic)
    
    // Prompt user to enter number of disks
    printf("Enter the number of disks:");
    scanf("%d", &n);   // Read number of disks
    
    // Display heading for the result
    printf("\nRequired moves:\n");
    
    // Call Tower of Hanoi function with rods S, T, and D
    TOH(n, 'S', 'T', 'D');
    
    return 0;   // End of program
}
