#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int numVertices;
    vector<__1::vector<int> >adjLists;

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
    }

    // Depth First Search (DFS) without stack
    void DFS(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < adjLists[vertex].size(); ++i) {
            int adjVertex = adjLists[vertex][i];
            if (!visited[adjVertex]) {
                DFS(adjVertex, visited);
            }
        }
    }

    // Breadth First Search (BFS) without queue
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        vector<int> tempQueue;
        tempQueue.push_back(startVertex);

        while (!tempQueue.empty()) {
            int current = tempQueue.front();
            tempQueue.erase(tempQueue.begin()); // Simulating dequeue operation
            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                for (int adjVertex : adjLists[current]) {
                    if (!visited[adjVertex]) {
                        tempQueue.push_back(adjVertex); // Simulating enqueue operation
                    }
                }
            }
        }
    }
};

// Example usage
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 5);

    vector<bool> visited(4, false);
    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2, visited);
    cout << endl;

    cout << "Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2);
    cout << endl;

    return 0;
}
