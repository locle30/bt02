#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Hàm Insertion Sort
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm Partition cho Quick Sort
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Hàm Quick Sort thuần túy
void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

// Hàm Hybrid Quick Sort (kết hợp với Insertion Sort)
void hybridQuickSort(vector<int>& arr, int left, int right, int threshold) {
    if (right - left + 1 <= threshold) {
        insertionSort(arr, left, right);
    } else {
        if (left < right) {
            int pivotIndex = partition(arr, left, right);
            hybridQuickSort(arr, left, pivotIndex - 1, threshold);
            hybridQuickSort(arr, pivotIndex + 1, right, threshold);
        }
    }
}

int main() {
    const int SIZE = 10000;
    const int THRESHOLD = 10;

    // Tạo mảng ngẫu nhiên
    vector<int> array(SIZE);
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100000;
    }

    // Hybrid Quick Sort
    vector<int> arrayHybrid = array;
    clock_t start = clock();
    hybridQuickSort(arrayHybrid, 0, arrayHybrid.size() - 1, THRESHOLD);
    double hybridTime = (double)(clock() - start) / CLOCKS_PER_SEC;

    // Quick Sort
    vector<int> arrayQuick = array;
    start = clock();
    quickSort(arrayQuick, 0, arrayQuick.size() - 1);
    double quickTime = (double)(clock() - start) / CLOCKS_PER_SEC;

    // Hiển thị thời gian thực thi
    cout << "Hybrid Quick Sort time: " << hybridTime << " seconds" << endl;
    cout << "Quick Sort time: " << quickTime << " seconds" << endl;

    // Kiểm tra tính đúng đắn
    if (arrayHybrid != vector<int>(array.begin(), array.end())) {
        cout << "Hybrid Quick Sort failed!" << endl;
    }
    if (arrayQuick != vector<int>(array.begin(), array.end())) {
        cout << "Quick Sort failed!" << endl;
    }

    return 0;
}
