--->AIM:- Implementation of Vertex Cover using Approximation Algorithm


--->PROGRAM:-

#include <stdio.h>

#define V 5   // Number of vertices

// Function to find approximate vertex cover
void findVertexCover(int graph[V][V])
{
    int visited[V]; // Array to represent vertex cover set

    // Initialize all vertices as not included in cover
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Traverse all edges
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // If edge exists and neither vertex is selected
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Include both vertices in vertex cover
                visited[u] = 1;
                visited[v] = 1;
            }
        }
    }

    // Print the vertex cover
    printf("Approximate Vertex Cover: ");
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n");

    // Call the function
    findVertexCover(graph);

    return 0;
}