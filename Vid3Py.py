import random
import time

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]  # Pivot cố định (ở giữa)
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def randomized_quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot_index = random.randint(0, len(arr) - 1)  # Chọn pivot ngẫu nhiên
    pivot = arr[pivot_index]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return randomized_quick_sort(left) + middle + randomized_quick_sort(right)

def measure_time(sort_function, arr):
    start_time = time.time()
    sort_function(arr)
    return time.time() - start_time

if __name__ == "__main__":
    array_size = 10000
    arr = [random.randint(0, 100000) for _ in range(array_size)]

    arr_copy1 = arr.copy()
    arr_copy2 = arr.copy()

    quick_sort_time = measure_time(quick_sort, arr_copy1)

    randomized_quick_sort_time = measure_time(randomized_quick_sort, arr_copy2)

    print(f"Quick Sort thời gian: {quick_sort_time:.6f} giây")
    print(f"Randomized Quick Sort thời gian: {randomized_quick_sort_time:.6f} giây")

    if randomized_quick_sort_time < quick_sort_time:
        print("Randomized Quick Sort nhanh hơn Quick Sort thông thường.")
    else:
        print("Quick Sort thông thường nhanh hơn hoặc tương đương Randomized Quick Sort.")