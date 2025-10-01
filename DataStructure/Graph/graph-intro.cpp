#include <bits/stdc++.h>
using namespace std;

// Graph Representation using Adjacency List
class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }
};

// Breadth-First Search (BFS)
void bfs(Graph& g, int start) {
    vector<bool> visited(g.V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : g.adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// Depth-First Search (DFS)
void dfsUtil(Graph& g, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : g.adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(g, neighbor, visited);
        }
    }
}

void dfs(Graph& g, int start) {
    vector<bool> visited(g.V, false);
    dfsUtil(g, start, visited);
    cout << endl;
}

// Dijkstra's Algorithm for Shortest Path (for weighted graphs)
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Example usage
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS starting from node 0: ";
    bfs(g, 0);

    cout << "DFS starting from node 0: ";
    dfs(g, 0);

    // Dijkstra's example
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    vector<int> dist = dijkstra(V, adj, 0);
    cout << "Dijkstra's shortest distances from node 0: ";
    for (int d : dist) cout << d << " ";
    cout << endl;

    return 0;
}