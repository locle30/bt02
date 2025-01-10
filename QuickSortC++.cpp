#include <iostream>
#include <vector>
using namespace std;

int partitionFunc(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partitionFunc(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Kết quả Quick Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
