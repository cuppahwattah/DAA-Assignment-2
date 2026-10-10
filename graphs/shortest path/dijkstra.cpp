
#include <iostream>
using namespace std;

#define INF 1000000000

void dijkstra(int graph[][10], int vertices, int start) {
    int distance[10];
    bool visited[10] = {false};

    for (int i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[start] = 0;

    for (int count = 0; count < vertices; count++) {
        int minimum = INF;
        int current = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && distance[i] < minimum) {
                minimum = distance[i];
                current = i;
            }
        }

        if (current == -1)
            break;

        visited[current] = true;

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] > 0 && !visited[i]) {
                int newDistance =
                    distance[current] + graph[current][i];

                if (newDistance < distance[i])
                    distance[i] = newDistance;
            }
        }
    }

    cout << "\nShortest distances from vertex "
         << start << ":\n";

    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INF)
            cout << start << " -> " << i << " : Unreachable\n";
        else
            cout << start << " -> " << i
                 << " : " << distance[i] << "\n";
    }
}

int main() {
    int vertices, edges;
    int graph[10][10] = {0};

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    if (vertices < 1 || vertices > 10) {
        cout << "Number of vertices must be between 1 and 10.\n";
        return 1;
    }

    cout << "Enter the number of edges: ";
    cin >> edges;

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        cout << "Invalid number of edges.\n";
        return 1;
    }

    cout << "Enter edges (u v weight), vertices numbered 0 to "
         << vertices - 1 << ":\n";

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        if (u < 0 || u >= vertices ||
            v < 0 || v >= vertices || u == v ||
            weight < 0) {
            cout << "Invalid edge or negative weight.\n";
            return 1;
        }

        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return 1;
    }

    dijkstra(graph, vertices, start);

    return 0;
}
