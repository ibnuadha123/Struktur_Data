#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    private:
        int numberVertex;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int banyakTitik) {
            numberVertex = banyakTitik;
            adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
        }

    void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight;
        } else {
            cout << "Index Invalid" << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numberVertex; i++) {
            for (int j = 0; j < numberVertex; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int minDistance(vector<int>& distance, vector<bool>& visited) {
        int min = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < numberVertex; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    void dijkstra(int source, int destination = -1) {
        vector<int> distance(numberVertex, INT_MAX);
        vector<bool> visited(numberVertex, false);
        vector<int> parent(numberVertex, -1);

        distance[source] = 0;

        for (int count = 0; count < numberVertex; count++) {
            int u = minDistance(distance, visited);

            if (u == -1)
                break;

            visited[u] = true;

            for (int v = 0; v < numberVertex; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];

                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        if (destination == -1) {
            cout << endl;
            cout << "jarak terpendek dari lokasi A:" << endl;

            for (int i = 0; i < numberVertex; i++) {
                cout << "A ke " << char('A' + i) << " : ";

                if (distance[i] == INT_MAX) {
                    cout << "tak terjangkau" << endl;
                } else {
                    cout << distance[i] << " km" << endl;
                }
            }
        } else {
            cout << endl;
            cout << "rute tercepat dari " << char('A' + source)
                 << " ke " << char('A' + destination) << ":" << endl;

            if (distance[destination] == INT_MAX) {
                cout << "lokasi tak terjangkau" << endl;
                return;
            }

            vector<int> route;
            int current = destination;

            while (current != -1) {
                route.push_back(current);
                current = parent[current];
            }

            for (int i = route.size() - 1; i >= 0; i--) {
                cout << char('A' + route[i]);

                if (i > 0)
                    cout << " -> ";
            }

            cout << endl;
            cout << "total jarak: " << distance[destination] << " km" << endl;
        }
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 4);
    graph.addEdge(4, 5, 3);

    graph.printAdjMatrix();

    graph.dijkstra(0);

    char asal, tujuan;

    cout << endl;
    cout << "masukkan lokasi asal (A-F): ";
    cin >> asal;
    cout << "masukkan lokasi tujuan (A-F): ";
    cin >> tujuan;

    asal = toupper(asal);
    tujuan = toupper(tujuan);

    if (asal >= 'A' && asal <= 'F' &&
        tujuan >= 'A' && tujuan <= 'F') {
        graph.dijkstra(asal - 'A', tujuan - 'A');
    } else {
        cout << "lokasi salah (A - F)" << endl;
    }

    return 0;
}
