# Iterative Binary Search
def binary_search_iterative(arr, target):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = l + (r - l) // 2 
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return -1


# Recursive Binary Search
def binary_search_recursive(arr, l, r, target):
    if l > r:
        return -1
    mid = l + (r - l) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, mid + 1, r, target)
    else:
        return binary_search_recursive(arr, l, mid - 1, target)


if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11]
    target = 7

    print("Iterative:", binary_search_iterative(arr, target))
    print("Recursive:", binary_search_recursive(arr, 0, len(arr) - 1, target))
