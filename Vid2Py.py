import random
import time

# Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Merge Sort
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left:left + n1]
    R = arr[mid + 1:mid + 1 + n2]

    i, j, k = 0, 0, left
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

sizes = [5000, 10000, 20000]
for size in sizes:
    random_array = [random.randint(0, 100000) for _ in range(size)]

    # Measure Bubble Sort
    bubble_array = random_array[:]
    start = time.time()
    bubble_sort(bubble_array)
    bubble_time = time.time() - start

    # Measure Merge Sort
    merge_array = random_array[:]
    start = time.time()
    merge_sort(merge_array, 0, len(merge_array) - 1)
    merge_time = time.time() - start

    print(f"Array size: {size}")
    print(f"Bubble Sort time: {bubble_time:.6f} seconds")
    print(f"Merge Sort time: {merge_time:.6f} seconds")
    print()
