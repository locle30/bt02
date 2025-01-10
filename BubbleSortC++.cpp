#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};

    auto start = chrono::high_resolution_clock::now();

    bubbleSort(arr);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Ket qua sau Bubble Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    cout << "Thoi gian chay: " << elapsed.count() << " giay" << endl;

    return 0;
}
