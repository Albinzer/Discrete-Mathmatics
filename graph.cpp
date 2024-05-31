// write a program for graph cloring by welch-powell algorithm 

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void welshPowell() {
        vector<pair<int, int>> degree; // (vertex, degree) pair
        for (int i = 0; i < V; ++i)
            degree.push_back({i, adj[i].size()});

        sort(degree.begin(), degree.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        map<int, int> color; // Map to store vertex-color pairs
        set<int> availableColors; // Set to store available colors for each vertex

        int chromaticNumber = 0; // Initialize chromatic number

        for (int i = 0; i < V; ++i) {
            int vertex = degree[i].first;
            int vertexDegree = degree[i].second;

            // Find the color to assign to the current vertex
            int assignedColor = 1;
            for (int neighbor : adj[vertex]) {
                if (color.find(neighbor) != color.end()) {
                    availableColors.insert(color[neighbor]);
                }
            }

            while (availableColors.find(assignedColor) != availableColors.end()) {
                assignedColor++;
            }

            color[vertex] = assignedColor;
            chromaticNumber = max(chromaticNumber, assignedColor);
            availableColors.clear();
        }

        // Print results
        cout << "Chromatic Number: " << chromaticNumber << endl;
        cout << "Vertex Colors:" << endl;
        for (auto& entry : color) {
            cout << "Vertex " << entry.first << " --> Color " << entry.second << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    graph.welshPowell();

    return 0;
}
