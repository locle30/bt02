using Random
using Dates

# Bubble Sort
function bubble_sort!(arr)
    n = length(arr)
    for i in 1:n
        for j in 1:(n - i)
            if arr[j] > arr[j + 1]
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            end
        end
    end
end

# Merge Sort
function merge!(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left:left + n1 - 1]
    R = arr[mid + 1:mid + n2]

    i, j, k = 1, 1, left
    while i <= n1 && j <= n2
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

function merge_sort!(arr, left, right)
    if left < right
        mid = div(left + right, 2)
        merge_sort!(arr, left, mid)
        merge_sort!(arr, mid + 1, right)
        merge!(arr, left, mid, right)
    end
end

sizes = [5000, 10000, 20000]
for size in sizes
    random_array = rand(1:100000, size)

    # Measure Bubble Sort
    bubble_array = copy(random_array)
    bubble_start = now()
    bubble_sort!(bubble_array)
    bubble_time = now() - bubble_start

    # Measure Merge Sort
    merge_array = copy(random_array)
    merge_start = now()
    merge_sort!(merge_array, 1, length(merge_array))
    merge_time = now() - merge_start

    println("Array size: $size")
    println("Bubble Sort time: $(Dates.value(bubble_time)) milliseconds")
    println("Merge Sort time: $(Dates.value(merge_time)) milliseconds")
    println()
end
