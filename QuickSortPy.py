def partition(arr, low, high):
    pivot = arr[high]  # Pivot element
    i = low - 1        # Index of smaller element

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap elements

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]
    quick_sort(arr, 0, len(arr) - 1)
    print("Sorted array:", arr)