#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, int& counter) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        counter++; // Count comparisons
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right, int& counter) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, counter);
        mergeSort(arr, mid + 1, right, counter);
        merge(arr, left, mid, right, counter);
    }
}

int partition(vector<int>& arr, int low, int high, int& counter) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        counter++; // Count comparisons
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& counter) {
    if (low < high) {
        int pi = partition(arr, low, high, counter);

        quickSort(arr, low, pi - 1, counter);
        quickSort(arr, pi + 1, high, counter);
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int counterMerge = 0, counterQuick = 0;

    // Merge Sort
    vector<int> mergeArr = arr;
    mergeSort(mergeArr, 0, mergeArr.size() - 1, counterMerge);
    cout << "Merge Sort comparisons: " << counterMerge << endl;

    // Quick Sort
    vector<int> quickArr = arr;
    quickSort(quickArr, 0, quickArr.size() - 1, counterQuick);
    cout << "Quick Sort comparisons: " << counterQuick << endl;

    return 0;
}
