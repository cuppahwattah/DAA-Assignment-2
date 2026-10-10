
#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n;
    int graph[10][10];

    cout << "Enter the number of vertices: ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Number of vertices must be between 1 and 10.\n";
        return 1;
    }

    cout << "Enter the adjacency matrix using only 0 and 1:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (i == j)
                graph[i][j] = 0;
            else if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INF &&
                    graph[k][j] != INF &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] =
                        graph[i][k] + graph[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
