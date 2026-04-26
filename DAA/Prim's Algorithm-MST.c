--->AIM:- Implementation of Minimum Spanning Tree using Prim's Algorithm


--->PROGRAM:-

#include <stdio.h>
#include <stdlib.h>

#define V 5   // Number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[])
{
    int min = 999999;   // Initialize minimum value
    int min_index = 0;

    for (int i = 0; i < V; i++)
    {
        // Select the unvisited vertex with smallest key
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the Minimum Spanning Tree
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0; // To store total cost of MST

    // Start from vertex 1 (since 0 is root)
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", total);
} 

// Function to implement Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values to pick minimum weight edge
    int visited[V];  // To track visited vertices

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = 999999;
        visited[i] = 0;
    }

    key[0] = 0;      // Start from vertex 0
    parent[0] = -1;  // Root has no parent

    // MST will have V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick minimum key vertex not yet included
        int u = minKey(key, visited);
        visited[u] = 1;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Update if:
            // 1. There is an edge
            // 2. Vertex not visited
            // 3. Weight is smaller than current key
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the resulting MST
    printPrimMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    // Call Prim's algorithm
    primMST(graph);

    return 0;
}