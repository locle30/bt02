#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;#include <iostream>
    #include <vector>
    #include <chrono>

    using namespace std;
    using namespace std::chrono;

    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
        }
    }

    int main() {
        vector<int> arr = {5, 2, 9, 1, 5};

        cout << "Mảng ban đầu: ";
        for (int x : arr) cout << x << " ";
        cout << endl;

        auto start = high_resolution_clock::now();
        selectionSort(arr);
        auto stop = high_resolution_clock::now();

        cout << "Kết quả sau Selection Sort: ";
        for (int x : arr) cout << x << " ";
        cout << endl;

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;

        return 0;
    }

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
