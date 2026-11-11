#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
    private :
    vector<pair<long long, string>> table;
    vector<int> status;

    int hash1(long long key) {
        return key % TABLE_SIZE;
    }

    int hash2(long long key) {
        return 7 - (key % 7);
    }

    public :
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(long long nim, string nama) {
        int index = hash1(nim);
        int step = hash2(nim);
        int initialIndex = index;

        int deletedIndex = -1;

        while (true) {
            if (status[index] == 1 && table[index].first == nim) {
                table[index].second = nama;
                cout << "NIM " << nim << " sudah ada, nama diperbarui" << endl;
                return;
            }

            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }

            if (status[index] == 0) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }

                table[index] = make_pair(nim, nama);
                status[index] = 1;
                cout << "Data " << nim << " - " << nama << " disimpan di index " << index << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(nim, nama);
            status[deletedIndex] = 1;
            cout << "Data " << nim << " - " << nama << " disimpan di index " << deletedIndex << endl;
        } else {
            cout << "tabel penuh" << endl;
        }
    }

    void search(long long nim) {
        int index = hash1(nim);
        int step = hash2(nim);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == nim) {
                cout << "Data ditemukan : " << table[index].second << " (index " << index << ")" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data tidak ditemukan" << endl;
    }

    void remove(long long nim) {
        int index = hash1(nim);
        int step = hash2(nim);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == nim) {
                status[index] = 2;
                cout << "Data berhasil dihapus" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data tidak ditemukan" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";

            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } else if (status[i] == 2) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int pilihan;
    long long nim;
    string nama;

    do {
        cout << endl;
        cout << "Data Mahasiswa" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Tampilkan hash table dan keluar" << endl;
        cout << "Pilih menu : ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid" << endl;
            pilihan = 0;
            continue;
        }

        if (pilihan == 1) {
            cout << "Masukkan NIM  : ";
            cin >> nim;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan nama : ";
            getline(cin, nama);
            ht.insert(nim, nama);
        } else if (pilihan == 2) {
            cout << "Masukkan NIM yang dicari : ";
            cin >> nim;
            ht.search(nim);
        } else if (pilihan == 3) {
            cout << "Masukkan NIM yang dihapus : ";
            cin >> nim;
            ht.remove(nim);
        } else if (pilihan != 4) {
            cout << "Menu tidak tersedia" << endl;
        }
    } while (pilihan != 4);

    cout << endl << "Isi hash table : " << endl;
    ht.display();

    return 0;
}