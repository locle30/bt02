def merge(arr, left, mid, right, counter):
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left:mid + 1]
    R = arr[mid + 1:right + 1]

    i = j = 0
    k = left
    while i < n1 and j < n2:
        counter[0] += 1  
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

def merge_sort(arr, left, right, counter):
    if left < right:
        mid = left + (right - left) // 2

        merge_sort(arr, left, mid, counter)
        merge_sort(arr, mid + 1, right, counter)

        merge(arr, left, mid, right, counter)

def partition(arr, low, high, counter):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        counter[0] += 1 
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high, counter):
    if low < high:
        pi = partition(arr, low, high, counter)

        quick_sort(arr, low, pi - 1, counter)
        quick_sort(arr, pi + 1, high, counter)

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]
    counter_merge = [0]
    counter_quick = [0]

    # Merge Sort
    merge_sort(arr.copy(), 0, len(arr) - 1, counter_merge)
    print("Merge Sort comparisons:", counter_merge[0])

    # Quick Sort
    quick_sort(arr.copy(), 0, len(arr) - 1, counter_quick)
    print("Quick Sort comparisons:", counter_quick[0])
