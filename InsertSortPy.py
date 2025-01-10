import time

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5]

    start_time = time.time()

    insertion_sort(arr)

    end_time = time.time()

    elapsed_time = (end_time - start_time) * 1000

    print("Kết quả sau Insertion Sort:", arr)
    print(f"Thời gian chạy: {elapsed_time:.4f} ms")
