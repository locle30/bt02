function quick_sort!(arr, left, right)
    if left >= right
        return
    end
    pivot = arr[(left + right) ÷ 2]  # Fixed pivot (middle element)
    i, j = left, right
    while i <= j
        while arr[i] < pivot
            i += 1
        end
        while arr[j] > pivot
            j -= 1
        end
        if i <= j
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
        end
    end
    quick_sort!(arr, left, j)
    quick_sort!(arr, i, right)
end

function randomized_quick_sort!(arr, left, right)
    if left >= right
        return
    end
    pivot_index = rand(left:right)  # Random pivot
    pivot = arr[pivot_index]
    i, j = left, right
    while i <= j
        while arr[i] < pivot
            i += 1
        end
        while arr[j] > pivot
            j -= 1
        end
        if i <= j
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
        end
    end
    randomized_quick_sort!(arr, left, j)
    randomized_quick_sort!(arr, i, right)
end

using Random

test_size = 10_000
arr = rand(1:100_000, test_size)
arr1 = copy(arr)
arr2 = copy(arr)

quick_start = time()
quick_sort!(arr1, 1, length(arr1))
quick_end = time()
println("Quick Sort time: ", quick_end - quick_start, " seconds")

random_start = time()
randomized_quick_sort!(arr2, 1, length(arr2))
random_end = time()
println("Randomized Quick Sort time: ", random_end - random_start, " seconds")