#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "masukkan jumlah kata: ";
    cin >> n;

    string data[100];
    cout << "masukkan " << n << " kata:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << endl << "data awal: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl << endl;

    for (int i = 1; i < n; i++) {
        string key = data[i];
        int j = i - 1;

        cout << "langkah " << i << " key = " << key << endl;

        while (j >= 0 && data[j] > key) {
            cout << "geser " << data[j] << " dari index " << j
                 << "ke index " << j + 1 << endl;
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;

        cout << "taruh " << key << " di index " << j + 1 << endl;

        cout << "hasil langkah " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << data[k] << " ";
        }
        cout << endl << endl;
    }

    cout << "hasil akhir: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}