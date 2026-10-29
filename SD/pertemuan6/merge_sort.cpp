#include <iostream>
#include <vector>
using namespace std;

void merge (int data[], int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (data[i] <= data[j]) {
            temp.push_back(data[i]);
            i++;
        } else {
            temp.push_back(data[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(data[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(data[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        data[left + k] = temp[k];
    }
}

void mergesort(int data[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergesort(data, left, mid);
    mergesort(data, mid + 1, right);

    merge(data, left, mid, right);
}

int main() {
    int data[] = {5, 2, 4, 1, 3};
    // 1, 2, 3, 4, 5
    int n = 5;

    mergesort(data, 0, n-1);

    cout << "Hasil Merge Sort : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}