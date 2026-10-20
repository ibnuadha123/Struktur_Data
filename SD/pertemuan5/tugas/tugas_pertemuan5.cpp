#include <iostream>
using namespace std;

int binarySearch(int data[], int n, int target) {
    int low = 0; //index awal
    int high = n-1; //index akhir

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n, target;

    cout << "masukkan jumlah data mahasiswa: ";
    cin >> n;

    if (n <= 0) {
        cout << "jumlah data harus lebih dari 0" << endl;
        return 0;
    }

    int data[n];

    for (int i = 0; i < n; i++) {
        cout << "masukkan nilai mahasiswa ke " << i + 1 << ": ";
        cin >> data[i];

        while (data[i] < 0 || data[i] > 100) {
            cout << "masukkan nilai antara 0 - 100: ";
            cin >> data[i];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    cout << "\ndata setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    cout << "\nmasukkan nilai yang ingin dicari: \n";
    cin >> target;

    while (target < 0 || target > 100) {
        cout << "masukkan nilai antara 0 - 100: ";
        cin >> target;
    }

    int hasil = binarySearch(data, n, target);

    if (hasil != -1) {
        cout << "data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "data tidak ditemukan" << endl;
    }

    return 0;
}