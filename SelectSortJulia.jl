using BenchmarkTools

function selection_sort!(arr)
    n = length(arr)
    for i in 1:(n - 1)
        min_index = i
        for j in (i + 1):n
            if arr[j] < arr[min_index]
                min_index = j
            end
        end
        if min_index != i
            arr[i], arr[min_index] = arr[min_index], arr[i]
        end
    end
    return arr
end

arr = [5, 2, 9, 1, 5]
println("Mảng ban đầu: ", arr)

@btime selection_sort!(copy(arr))

selection_sort!(arr)
println("Kết quả sau Selection Sort: ", arr)
