--->AIM:- Implementation of Randomized Algorithm (Quicksort)


--->PROGRAM:-

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (Lomuto partition scheme)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // Choose last element as pivot
    int i = (low - 1);       // Index of smaller element

    // Traverse array and rearrange elements
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]); // Place smaller element on left
        }
    }

    // Place pivot at correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return pivot index
}

// QuickSort function (Divide and Conquer)
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Randomized pivot selection
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    // Seed random number generator
    srand(time(NULL));

    // Input number of elements
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n]; // Array to store elements

    // Input elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbersToSort[i]);

    // Call QuickSort
    quickSort(numbersToSort, 0, n - 1);

    // Print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", numbersToSort[i]);

    return 0;
}
