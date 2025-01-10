function merge!(arr, left, mid, right, counter)
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left:left + n1 - 1]
    R = arr[mid + 1:mid + n2]

    i, j, k = 1, 1, left
    while i <= n1 && j <= n2
        counter[] += 1  # Count comparisons
        if L[i] <= R[j]
            arr[k] = L[i]
            i += 1
        else
            arr[k] = R[j]
            j += 1
        end
        k += 1
    end

    while i <= n1
        arr[k] = L[i]
        i += 1
        k += 1
    end

    while j <= n2
        arr[k] = R[j]
        j += 1
        k += 1
    end
end

function merge_sort!(arr, left, right, counter)
    if left < right
        mid = div(left + right, 2)
        merge_sort!(arr, left, mid, counter)
        merge_sort!(arr, mid + 1, right, counter)
        merge!(arr, left, mid, right, counter)
    end
end

function partition!(arr, low, high, counter)
    pivot = arr[high]
    i = low - 1

    for j in low:high - 1
        counter[] += 1
        if arr[j] <= pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        end
    end

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1
end

function quick_sort!(arr, low, high, counter)
    if low < high
        pi = partition!(arr, low, high, counter)
        quick_sort!(arr, low, pi - 1, counter)
        quick_sort!(arr, pi + 1, high, counter)
    end
end

arr = [5, 2, 9, 1, 5, 6]

# Merge Sort
merge_arr = copy(arr)
merge_counter = Ref(0) 
merge_sort!(merge_arr, 1, length(merge_arr), merge_counter)
println("Merge Sort comparisons: ", merge_counter[])

# Quick Sort
quick_arr = copy(arr)
quick_counter = Ref(0)  
quick_sort!(quick_arr, 1, length(quick_arr), quick_counter)
println("Quick Sort comparisons: ", quick_counter[])
