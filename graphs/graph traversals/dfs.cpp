
#include <iostream>
using namespace std;

void dfs(int graph[][10], bool visited[], int vertices, int current) {
    visited[current] = true;
    cout << current << " ";

    for (int i = 0; i < vertices; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(graph, visited, vertices, i);
        }
    }
}

int main() {
    int vertices, edges;
    int graph[10][10] = {0};
    bool visited[10] = {false};

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    if (vertices < 1 || vertices > 10) {
        cout << "Invalid number of vertices.";
        return 1;
    }

    cout << "Enter the number of edges: ";
    cin >> edges;

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        cout << "Invalid number of edges.";
        return 1;
    }

    cout << "Enter the edges (vertices numbered 0 to "
         << vertices - 1 << "):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= vertices ||
            v < 0 || v >= vertices) {
            cout << "Invalid vertex number.";
            return 1;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.";
        return 1;
    }

    cout << "DFS Traversal: ";
    dfs(graph, visited, vertices, start);

    return 0;
}
