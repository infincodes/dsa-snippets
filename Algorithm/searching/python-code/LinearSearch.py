def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # found, return index
    return -1  # not found


if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50]
    target = 30
    result = linear_search(arr, target)

    if result != -1:
        print(f"Element found at index {result}")
    else:
        print("Element not found")
