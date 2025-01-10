import time  

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5]

    start_time = time.time()

    bubble_sort(arr)

    end_time = time.time()
    elapsed_time = end_time - start_time

    print("Kết quả sau Bubble Sort:", arr)
    print(f"Thời gian chạy: {elapsed_time:.8f} giây")
