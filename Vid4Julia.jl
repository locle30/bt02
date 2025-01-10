function insertion_sort!(arr, left, right)
    for i in left+1:right
        key = arr[i]
        j = i - 1
        while j >= left && arr[j] > key
            arr[j + 1] = arr[j]
            j -= 1
        end
        arr[j + 1] = key
    end
end

function partition!(arr, left, right)
    pivot = arr[right]
    i = left - 1
    for j in left:right-1
        if arr[j] <= pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        end
    end
    arr[i + 1], arr[right] = arr[right], arr[i + 1]
    return i + 1
end

function quick_sort!(arr, left, right)
    if left < right
        pivot_index = partition!(arr, left, right)
        quick_sort!(arr, left, pivot_index - 1)
        quick_sort!(arr, pivot_index + 1, right)
    end
end

# Hàm Hybrid Quick Sort (kết hợp với Insertion Sort)
function hybrid_quick_sort!(arr, left, right, threshold)
    if right - left + 1 <= threshold
        insertion_sort!(arr, left, right)
    elseif left < right
        pivot_index = partition!(arr, left, right)
        hybrid_quick_sort!(arr, left, pivot_index - 1, threshold)
        hybrid_quick_sort!(arr, pivot_index + 1, right, threshold)
    end
end

# Hàm chính
function main()
    SIZE = 10_000
    THRESHOLD = 10
    array = [rand(1:100000) for _ in 1:SIZE]

    # Hybrid Quick Sort
    array_hybrid = copy(array)
    start_time = time()
    hybrid_quick_sort!(array_hybrid, 1, length(array_hybrid), THRESHOLD)
    hybrid_time = time() - start_time

    # Quick Sort
    array_quick = copy(array)
    start_time = time()
    quick_sort!(array_quick, 1, length(array_quick))
    quick_time = time() - start_time

    # Hiển thị thời gian thực thi
    println("Hybrid Quick Sort time: $hybrid_time seconds")
    println("Quick Sort time: $quick_time seconds")

    # Kiểm tra tính đúng đắn
    if array_hybrid != sort(array)
        println("Hybrid Quick Sort failed!")
    end
    if array_quick != sort(array)
        println("Quick Sort failed!")
    end
end

# Gọi hàm chính
main()
