#include <iostream>

#define MAX_VERTICES 100

using namespace std;

// Graph structure
class Graph {
public:
    int V; // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix

    // Constructor to initialize the graph
    Graph(int vertices) {
        V = vertices;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adj[i][j] = 0; // Initialize all edges to 0
            }
        }
    }

    // Add an edge to the graph (for undirected graph)
    void addEdge(int src, int dest) {
        adj[src][dest] = 1; // Set adjacency for src -> dest
        adj[dest][src] = 1; // Set adjacency for dest -> src
    }

    // Perform BFS traversal
    void BFS(int start) {
        int queue[MAX_VERTICES]; // Queue for BFS
        bool visited[MAX_VERTICES] = { false }; // Visited array
        int front = 0, rear = 0;

        // Start with the starting vertex
        visited[start] = true;
        queue[rear++] = start; // Enqueue the start vertex

        cout << "BFS Traversal starting from vertex " << start << ":\n";

        while (front < rear) {
            // Dequeue the front vertex
            int current = queue[front++];
            cout << current << " ";

            // Explore all adjacent vertices
            for (int i = 0; i < V; i++) {
                if (adj[current][i] && !visited[i]) {
                    visited[i] = true;  // Mark as visited
                    queue[rear++] = i; // Enqueue the vertex
                }
            }
        }

        cout << endl;
    }
};

// Driver code
int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Create and initialize the graph
    Graph graph(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (source and destination):\n";
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    // Perform BFS traversal
    graph.BFS(startVertex);

    return 0;
}
