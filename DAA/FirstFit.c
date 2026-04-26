--->AIM:- Implementation of First Fit Algorithm in Bin Packing
    

--->PROGRAM:-
    
#include <stdio.h>

// Function to implement First Fit bin packing
void firstFit(int items[], int n, int capacity)
{
    int bin[n];        // Array to store remaining capacity of bins
    int binCount = 0;  // Number of bins used
    printf("\nExecuting First Fit algorithm\n");

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = 0;

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        if(items[i]>capacity)
        {
              printf("Item %d with size %d can't be placed in any bin\n", i+1, items[i]);
              continue;
        }
        int placed = 0; // Flag to check if item is placed

        // Try placing item in existing bins
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i]; // Reduce remaining capacity
                printf("Item %d with weight %d placed in Bin %d\n",
                       i + 1, items[i], j + 1);
                placed = 1;
                break;
            }
        }

        // If item is not placed in any existing bin
        if (!placed)
        {
            // Create new bin and place item
            bin[binCount] = capacity;
            bin[binCount]-= items[i];

            printf("Item %d with weight %d placed in Bin %d\n",
                   i + 1, items[i], binCount + 1);

            binCount++; // Increase bin count
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    int items[n]; // Array to store item sizes

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Validate item size
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--; // Retry input
        }
    }

    // Call First Fit algorithm
    firstFit(items, n, capacity);

    return 0;
}
