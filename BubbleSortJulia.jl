function bubble_sort!(arr)
    n = length(arr)
    for i in 1:(n-1)
        swapped = false
        for j in 1:(n-i)
            if arr[j] > arr[j+1]
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = true
            end
        end
        if !swapped
            break
        end
    end
    return arr
end

arr = [5, 2, 9, 1, 5]

start_time = time()

bubble_sort!(arr)

end_time = time()
elapsed_time = end_time - start_time

println("Kết quả sau Bubble Sort: ", arr)
println("Thời gian chạy: ", elapsed_time, " giây")
