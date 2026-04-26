--->AIM:- Implementation of Best Fit Algorithm in Bin Packing


--->PROGRAM:-

#include <stdio.h>

// Function to implement Best Fit bin packing
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];        // Array to store remaining space in each bin
    int binCount = 0;  // Number of bins used

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;         // Index of best bin for current item
        int minSpace = capacity + 1; // Minimum leftover space

        // Find the best bin (least remaining space after placing item)
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If suitable bin found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // Place item in that bin
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create new bin and place item
            bin[binCount] = capacity - items[i];

            printf("Item %d (weight: %d) placed in Bin %d\n",
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

    int items[n]; // Array to store item sizes

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

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
            i--; // Retry input for same item
        }
    }

    // Call Best Fit algorithm
    bestFit(items, n, capacity);

    return 0;
}
