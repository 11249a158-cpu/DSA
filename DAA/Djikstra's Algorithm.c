--->AIM:- Implementation of Djikstra's Algorithm


--->PROGRAM:-

#include <stdio.h>

// Number of vertices
#define V 5
#define INF 999999  // Represent infinity (large value)

// Function to find the vertex with minimum distance
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;

    // Traverse all vertices
    for (int v = 0; v < V; v++)
    {
        // Select the unvisited vertex with smallest distance
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V])
{
    int dist[V];     // Array to store shortest distances
    int visited[V];  // Track visited vertices

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0; // Distance of source vertex (0) is 0

    // Loop to find shortest path for all vertices
    for (int count = 0; count < V; count++)
    {
        int u = extractMin(dist, visited);

        // If no reachable vertex remains
        if (u == -1)
            break;

        visited[u] = 1; // Mark vertex as visited

        // Update distances of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            // Check if there is an edge and vertex is not visited
            if (graph[u][j] > 0 && !visited[j])
            {
                // Relaxation step
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Print shortest distances from source
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
        printf("%d --> %d\n", i, dist[i]);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    // Call Dijkstra's algorithm
    dijkstra(graph);

    return 0;
}