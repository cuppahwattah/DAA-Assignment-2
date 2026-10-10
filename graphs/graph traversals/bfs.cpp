
#include <iostream>
#include <queue>
using namespace std;

void bfs(int graph[][10], int vertices, int start) {
    bool visited[10] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int vertices, edges;
    int graph[10][10] = {0};

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

    cout << "BFS Traversal: ";
    bfs(graph, vertices, start);

    return 0;
}
