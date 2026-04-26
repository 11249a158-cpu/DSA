--->AIM:- To implement Travelling Salesman Problem using dynamic programming



--->Program:-


#include<stdio.h>
#include<limits.h>   

// Define maximum number of cities
#define MAXN 15      
#define INF INT_MAX  // Represents infinity

// Global variables
int n;                     // Number of cities 
int d[MAXN][MAXN];         // Cost matrix
int dp[MAXN][1<<MAXN];     //DP table for memoization

// Function to compute minimum cost (TSP using DP + bitmasking)
int g(int i, int S)
{
    // Base case: if no cities left, return cost to starting city
    if(S == 0)
        return d[i][0];

    // If already computed, return stored value
    if(dp[i][S] != -1)
        return dp[i][S];

    int minCost = INF;

    // Try visiting each city in set S
    for (int k = 0; k < n; k++)
    {
        // Check if city k is in S
        if(S & (1 << k))
        {
            int cost = d[i][k] + g(k, S & ~(1 << k));

            if (cost < minCost)
            {
                minCost = cost;
            }
        }
    }

    return dp[i][S] = minCost;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize DP table
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
        {    
             dp[i][mask] = -1;
        }
    

    // Create set S (cities except 0)
    int S = 0;
    for (int i = 1; i < n; i++)
        S |= (1 << i);

    // Solve TSP starting from city 0
    int result = g(0, S);

    printf("Given Cost Matrix\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
        printf("|\n");
    }

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}