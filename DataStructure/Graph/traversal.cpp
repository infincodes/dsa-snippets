#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;  
    int vertices; 

public:
    Graph(int vertices) {
        this->vertices = vertices;
        adjList.resize(vertices);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int start) {
        vector<bool> visited(vertices, false); 
        dfsUtil(start, visited);
    }

    void dfsUtil(int node, vector<bool>& visited) {
        cout << node << " ";
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void bfs(int start) {
        vector<bool> visited(vertices, false);  
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);


    cout << "DFS Traversal starting from vertex 0: ";
    g.dfs(0);
    cout << endl;

    cout << "BFS Traversal starting from vertex 0: ";
    g.bfs(0);
    cout << endl;

    return 0;
}
