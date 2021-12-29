def find_even_index(arr):
    sum_left = 0
    index = None
    
    for j in range(len(arr)):
        sum_right = sum(arr[i] for i in range(j, len(arr)))
        if (sum_left == 0) and (sum_left == sum_right):
                return j
        sum_right = 0
        sum_right = sum(arr[i] for i in range(j + 1, len(arr)))
        if sum_left == sum_right:
            return j
        sum_left += arr[j]   
    if index == None:
            return -1
print(find_even_index([1,2,3,4,3,2,1]))