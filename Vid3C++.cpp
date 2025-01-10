#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

void randomizedQuickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = arr[pivotIndex];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    randomizedQuickSort(arr, left, j);
    randomizedQuickSort(arr, i, right);
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int SIZE = 10000;
    vector<int> arr(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100000;
    }

    vector<int> arr1 = arr;
    vector<int> arr2 = arr;

    clock_t start = clock();
    quickSort(arr1, 0, arr1.size() - 1);
    clock_t end = clock();
    double quickSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Quick Sort time: " << quickSortTime << " seconds" << endl;

    start = clock();
    randomizedQuickSort(arr2, 0, arr2.size() - 1);
    end = clock();
    double randomizedQuickSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Randomized Quick Sort time: " << randomizedQuickSortTime << " seconds" << endl;

    cout << "\nPhân tích:\n";
    if (randomizedQuickSortTime < quickSortTime) {
        cout << "Thuật toán Randomized Quick Sort nhanh hơn so với Standard Quick Sort trong trường hợp này." << endl;
    } else if (randomizedQuickSortTime > quickSortTime) {
        cout << "Thuật toán Standard Quick Sort nhanh hơn so với Randomized Quick Sort trong trường hợp này." << endl;
    } else {
        cout << "Cả hai thuật toán có hiệu suất tương đương trong trường hợp này." << endl;
    }
    cout << "\nLưu ý: Hiệu suất có thể thay đổi dựa trên dữ liệu đầu và tính ngẫu nhiên." << endl;

    return 0;
}
