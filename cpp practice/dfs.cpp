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

    // Utility function for DFS
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true; // Mark the current vertex as visited
        cout << vertex << " "; // Print the current vertex

        // Recur for all adjacent vertices
        for (int i = 0; i < V; i++) {
            if (adj[vertex][i] && !visited[i]) {
                DFSUtil(i, visited); // Recur for unvisited adjacent vertex
            }
        }
    }

    // Perform DFS traversal
    void DFS(int start) {
        bool visited[MAX_VERTICES] = { false }; // Visited array

        cout << "DFS Traversal starting from vertex " << start << ":\n";
        DFSUtil(start, visited); // Start DFS from the given vertex
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    // Perform DFS traversal
    graph.DFS(startVertex);


    //test case
    //input 5 6 0 1 0 2 1 3 1 4 2 4 3 0 0
    //output 0 1 3 4 2

    return 0;
}
