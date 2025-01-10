#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; ++i) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> sizes = {5000, 10000, 20000};

    for (int size : sizes) {
        vector<int> random_array(size);

        for (int i = 0; i < size; ++i) {
            random_array[i] = rand() % 100000;
        }

        // Measure Bubble Sort
        vector<int> bubble_array = random_array;
        auto start = chrono::high_resolution_clock::now();
        bubble_sort(bubble_array);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> bubble_time = end - start;

        // Measure Merge Sort
        vector<int> merge_array = random_array;
        start = chrono::high_resolution_clock::now();
        merge_sort(merge_array, 0, merge_array.size() - 1);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> merge_time = end - start;

        cout << "Array size: " << size << endl;
        cout << "Bubble Sort time: " << bubble_time.count() << " seconds" << endl;
        cout << "Merge Sort time: " << merge_time.count() << " seconds" << endl;
        cout << endl;
    }

    return 0;
}
