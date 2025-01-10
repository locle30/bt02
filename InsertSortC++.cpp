#include <iostream>
#include <vector>
#include <chrono> // Thư viện để đo thời gian
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};

    auto start = chrono::high_resolution_clock::now();

    insertionSort(arr);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;

    cout << "Ket qua sau Insertion Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Thoi gian chay: " << elapsed.count() << " ms" << endl;

    return 0;
}
