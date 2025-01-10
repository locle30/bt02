function insertion_sort!(arr)
    n = length(arr)
    for i in 2:n
        key = arr[i]
        j = i - 1
        while j >= 1 && arr[j] > key
            arr[j + 1] = arr[j]
            j -= 1
        end
        arr[j + 1] = key
    end
    return arr
end

arr = [5, 2, 9, 1, 5]

elapsed_time = @elapsed insertion_sort!(arr)

println("Kết quả sau Insertion Sort: ", arr)
println("Thời gian chạy: $(elapsed_time * 1000) ms")
