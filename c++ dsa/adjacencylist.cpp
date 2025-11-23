#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V) // Constructor
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v) // Function to add an edge to graph
    {
        adj[u].push_back(v); // Add v to u’s list.
        adj[v].push_back(u); // Add u to v’s list (for undirected graph)
    }
    void printGraph() // Function to print the adjacency list representation of graph
    {
        for (int v = 0; v < V; v++)
        {
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto neighbor : adj[v])
                cout << "-> " << neighbor;
            cout << "\n";
        }
    }

    ~Graph() // Destructor to free memory
    {
        delete[] adj;
    }
};

int main()
{
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph(); // Print the adjacency list representation of the graph

    return 0;
}