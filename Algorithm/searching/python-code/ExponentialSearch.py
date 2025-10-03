# Binary Search (helper function)
def binary_search(arr, l, r, target):
    while l <= r:
        mid = l + (r - l) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return -1


# Exponential Search
def exponential_search(arr, target):
    if arr[0] == target:
        return 0
    n = len(arr)
    i = 1
    while i < n and arr[i] <= target:
        i *= 2
    return binary_search(arr, i // 2, min(i, n - 1), target)


if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11, 13]
    target = 11
    print("Exponential Search:", exponential_search(arr, target))
