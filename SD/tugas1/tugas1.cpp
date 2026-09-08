#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    int arr[3][3][4];
    int angka = 2;
 
    for (int layer = 0; layer < 3; layer++) {
        for (int baris = 0; baris < 3; baris++) {
            for (int kolom = 0; kolom < 4; kolom++) {
                arr[layer][baris][kolom] = angka;
                angka += 2;
            }
        }
    }
 
    for (int layer = 0; layer < 3; layer++) {
        cout << "Lapis ke-" << (layer + 1) << ":" << endl;
 
        for (int baris = 0; baris < 3; baris++) {
            for (int kolom = 0; kolom < 4; kolom++) {
                cout << setw(4) << arr[layer][baris][kolom];
            }
            cout << endl;
        }
        cout << endl;
    }
 
    return 0;
}
