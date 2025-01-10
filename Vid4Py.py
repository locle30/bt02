import time
import random

def insertion_sort(arr, left, right):
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def hybrid_quick_sort(arr, left, right, threshold):
    if right - left + 1 <= threshold:
        insertion_sort(arr, left, right)
    else:
        if left < right:
            pivot_index = partition(arr, left, right)
            hybrid_quick_sort(arr, left, pivot_index - 1, threshold)
            hybrid_quick_sort(arr, pivot_index + 1, right, threshold)

def quick_sort(arr, left, right):
    if left < right:
        pivot_index = partition(arr, left, right)
        quick_sort(arr, left, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, right)

def partition(arr, left, right):
    pivot = arr[right]
    i = left - 1
    for j in range(left, right):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[right] = arr[right], arr[i + 1]
    return i + 1

if __name__ == "__main__":
    SIZE = 10000
    THRESHOLD = 10
    array = [random.randint(0, 100000) for _ in range(SIZE)]

    # Hybrid Quick Sort
    array_hybrid = array[:]
    start_time = time.time()
    hybrid_quick_sort(array_hybrid, 0, len(array_hybrid) - 1, THRESHOLD)
    hybrid_time = time.time() - start_time

    # Quick Sort
    array_quick = array[:]
    start_time = time.time()
    quick_sort(array_quick, 0, len(array_quick) - 1)
    quick_time = time.time() - start_time

    print(f"Hybrid Quick Sort time: {hybrid_time:.6f} seconds")
    print(f"Quick Sort time: {quick_time:.6f} seconds")

    # Verify correctness
    assert array_hybrid == sorted(array), "Hybrid Quick Sort failed!"
    assert array_quick == sorted(array), "Quick Sort failed!"
