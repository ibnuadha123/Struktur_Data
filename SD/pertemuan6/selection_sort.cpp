#include <iostream>
using namespace std;

int main() {
    int data[] = {5, 2, 4, 1, 3};
    int n = 5;

    for (int i = 0; i < n - i; i ++) {
        int minIndex = i; // patokan awal index = 0

        for (int j = i; j < n; j++) { // j = 1
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        swap (data[i], data[minIndex]);
    }

    cout << "hasil selection sort: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
 }