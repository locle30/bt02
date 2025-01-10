import time

def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]

arr = [5, 2, 9, 1, 5]
print("Mảng ban đầu:", arr)

start_time = time.time()
selection_sort(arr)
end_time = time.time()

print("Kết quả sau Selection Sort:", arr)
print("Thời gian thực thi: {:.6f} giây".format(end_time - start_time))
