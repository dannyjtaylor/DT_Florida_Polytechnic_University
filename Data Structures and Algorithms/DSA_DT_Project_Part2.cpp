/*#include <iostream>
#include <queue>
#include <utility>
// #include <list>
// /*
// class Graph
// {
//     // Number of vertices
//     int V;
//     // Adjacency list representation
//     // Pair of a neighbor vertex and a weight for every edge
//     list<pair<int vertex, int weight>> *adj;

// public:
//     Graph(int V);
//     // Function to add an edge to graph
//     void addEdge(int u, int v, int w) {

//     }
//     // Print MST using Prim's algorithm
//     void primMST();
// };

// // Allocates memory for adjacency list
// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list< pair<int, int>> [V];
// }


// int main()
// {
//     priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
//     int V = 8;
//     Graph g(V);
//     g.addEdge(0, 1, 5);
//     g.addEdge(0, 4, 8);
//     g.addEdge(1, 2, 8);
//     g.addEdge(1, 7, 11);
//     g.addEdge(2, 3, 7);
//     g.addEdge(2, 7, 2);
//     g.addEdge(3, 6, 9);
//     g.addEdge(3, 5, 14);
//     g.addEdge(4, 5, 10);
//     g.addEdge(5, 6, 2);
//     g.addEdge(6, 7, 3);

//     //print minimum spanning tree
//     g.primMST();
//     return 0;
// }

// */
// #include <iostream>
// #include <vector>
// #include <list>
// #include <queue>
// #include <utility>
// #define INF 100

// using namespace std;

// class Graph {
// private:
//     int V;  // Number of vertices
//     list<pair<int, int>>* adj;  // Adjacency list for the graph

// public:
//     // Constructor to initialize the graph with V vertices
//     Graph(int V) {
//         this->V = V;
//         adj = new list<pair<int, int>>[V];  // Allocate memory for adjacency list
//     }

//     // Function to add an edge to the graph
//     void addEdge(int u, int v, int w) {
//         adj[u].push_back(make_pair(v, w));  // Add edge u-v with weight w
//         adj[v].push_back(make_pair(u, w));  // Since it's an undirected graph
//     }

//     // Function to implement Prim's Algorithm for MST
//     void primMST() {
//         // Priority queue to select the edge with the minimum weight
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//         // Vector to store the minimum weight of each vertex
//         vector<int> value(V, INF);
        
//         // Vector to store the parent of each vertex in MST
//         vector<int> parent(V, -1);

//         // Vector to keep track of vertices included in MST
//         vector<bool> inMST(V, false);

//         // Start from vertex 0, set its value to 0 and push it into the priority queue
//         value[0] = 0;
//         pq.push(make_pair(0, 0));

//         while (!pq.empty()) {
//             // Extract the vertex with the minimum weight edge
//             int u = pq.top().second;
//             pq.pop();

//             // Skip if the vertex is already included in MST
//             if (inMST[u]) continue;

//             // Include vertex u in MST
//             inMST[u] = true;

//             // Iterate over the neighbors of u
//             for (auto& neighbor : adj[u]) {
//                 int v = neighbor.first;  // Neighbor vertex
//                 int weight = neighbor.second;  // Weight of the edge

//                 // If the vertex v is not in MST and the weight of the edge (u, v) is less than the current value of v
//                 if (!inMST[v] && weight < value[v]) {
//                     value[v] = weight;
//                     parent[v] = u;
//                     pq.push(make_pair(weight, v));  // Push (weight, vertex) into the priority queue
//                 }
//             }
//         }

//         // Print the MST edges (parent array will give us the MST)
//         for (int i = 1; i < V; ++i) {
//             if (parent[i] != -1) {
//                 cout << parent[i] << " - " << i << endl;
//             }
//         }
//     }
// };

// int main() {
//     int V = 8;
//     Graph g(V);
//     g.addEdge(0, 1, 5);
//     g.addEdge(0, 4, 8);
//     g.addEdge(1, 2, 8);
//     g.addEdge(1, 7, 11);
//     g.addEdge(2, 3, 7);
//     g.addEdge(2, 7, 2);
//     g.addEdge(3, 6, 9);
//     g.addEdge(3, 5, 14);
//     g.addEdge(4, 5, 10);
//     g.addEdge(5, 6, 2);
//     g.addEdge(6, 7, 3);

//     g.primMST();

//     return 0;
// }


#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#define INF 1000

using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    list<pair<int, int>>* adj;  // Adjacency list for the graph

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int>>[V];  // Allocate memory for adjacency list
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));  // Add edge u-v with weight w
        adj[v].push_back(make_pair(u, w));  // Since it's an undirected graph
    }

    // Function to implement Prim's Algorithm for MST
    void primMST() {
    // Priority queue to select the edge with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to store the minimum weight of each vertex
    vector<int> value(V, INF);
    
    // Vector to store the parent of each vertex in MST
    vector<int> parent(V, -1);

    // Vector to keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Start from vertex 0, set its value to 0 and push it into the priority queue
    value[0] = 0;
    pq.push(make_pair(0, 0));

    // Store the edges of the MST in order
    vector<pair<int, int>> mstEdges;

    while (!pq.empty()) {
        // Extract the vertex with the minimum weight edge
        int u = pq.top().second;
        pq.pop();

        // Skip if the vertex is already included in MST
        if (inMST[u]) continue;

        // Include vertex u in MST
        inMST[u] = true;

        // If u has a parent, add the edge (parent[u], u) to the MST
        if (parent[u] != -1) {
            mstEdges.push_back({parent[u], u});
        }

        // Iterate over the neighbors of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;  // Neighbor vertex
            int weight = neighbor.second;  // Weight of the edge

            // If the vertex v is not in MST and the weight of the edge (u, v) is less than the current value of v
            if (!inMST[v] && weight < value[v]) {
                value[v] = weight;
                parent[v] = u;
                pq.push(make_pair(weight, v));  // Push (weight, vertex) into the priority queue
            }
        }
    }

    // Print the edges in the order they were added to the MST
    for (const auto& edge : mstEdges) {
        cout << edge.first << " - " << edge.second << endl;
    }
    }
};


int main() {
    int V = 9;
    Graph g(V);
    
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 9);
    g.addEdge(1, 2, 12);
    g.addEdge(1, 4, 9);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 8);
    g.addEdge(5, 3, 7);
    g.addEdge(5, 6, 3);
    g.addEdge(3, 4, 3);
    // g.addEdge(0, 1, 5);
    g.addEdge(4, 6, 5);
    g.addEdge(4, 7, 8);
    g.addEdge(7, 6, 15);
    g.addEdge(7, 8, 10);
    g.addEdge(6, 8, 11);

    // g.addEdge(0, 1, 5);
    // g.addEdge(0, 4, 8);
    // g.addEdge(1, 2, 8);
    // g.addEdge(1, 7, 11);
    // g.addEdge(2, 3, 7);
    // g.addEdge(2, 7, 2);
    // g.addEdge(3, 6, 9);
    // g.addEdge(3, 5, 14);
    // g.addEdge(4, 5, 10);
    // g.addEdge(5, 6, 2);
    // g.addEdge(6, 7, 3);

    g.primMST();

    return 0;
}