#include <iostream>
#include <vector>
#include <queue>
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
    
    void addEdge(int i, int j) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;
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
    void bfs(int startVertex) {
        vector<bool> visited(numberVertex, false);
        queue<int> titikVisit;

        visited[startVertex] = true;
        titikVisit.push(startVertex);

        cout << "urutan BFS: ";

        while (!titikVisit.empty()) {
            int currentVertex = titikVisit.front();
            titikVisit.pop();

            cout << char('A' + currentVertex) << " ";

            for (int i = 0; i < numberVertex; i++) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    titikVisit.push(i);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph graph(6);
    int jumlahEdge;
    char asal, tujuan, start;

    cout << "masukkan jumlah edge: ";
    cin >> jumlahEdge;

    cout << "masukkan edge (A B):" << endl;

    for (int i = 0; i < jumlahEdge; i++) {
        cin >> asal >> tujuan;

        asal = toupper(asal);
        tujuan = toupper(tujuan);

        if (asal >= 'A' && asal <= 'F' &&
            tujuan >= 'A' && tujuan <= 'F') {
            graph.addEdge(asal - 'A', tujuan - 'A');
        } else {
            cout << "vertex harus antara A sampai F" << endl;
            i--;
        }
    }

    graph.printAdjMatrix();

    cout << "masukkan vertex awal (A-F): ";
    cin >> start;
    start = toupper(start);

    if (start >= 'A' && start <= 'F') {
        graph.bfs(start - 'A');
    } else {
        cout << "vertex awal salah" << endl;
    }

    return 0;
}