---> AIM:- Implementation of Fractional Knapsack


---> Program:-


#include <stdio.h>

// Structure to store item details
struct Item
{
    int weight;   // (weight of item)
    int value;    // (value of item)
    float ppw;    // profit per weight (value/weight)
};

// Function to sort items in descending order of profit per weight
void sort(struct Item items[], int n)
{
    struct Item temp;

    // Bubble sort based on ppw
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if next item has higher profit per weight
            if (items[j].ppw < items[j + 1].ppw)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    printf("Items sorted by value/weight ratio:\n");
    
    for(int i=0;i<n;i++)
    {
        printf("Item %: weight=%d, value=%d, ratio=%.2f\n",i+1, items[i].weight, items[i].value, items[i].ppw);
    }
}

int main()
{
    int n;
    float capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Edge case: invalid number of items
    if (n <= 0)
        return 1;

    // Declare array of items (VLA - Variable Length Array)
    struct Item items[n];

    // Input weight and value for each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate profit per weight
        items[i].ppw = (float)items[i].value / items[i].weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items by profit per weight (greedy step)
    sort(items, n);

    float totalProfit = 0.0;

    // Traverse sorted items
    for (int i = 0; i < n; i++)
    {
        // If full item can be taken
        if (capacity >= items[i].weight)
        {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            // Take fraction of item
            totalProfit += items[i].ppw * capacity;
            break;  // Knapsack is full
        }
    }

    // Output maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}