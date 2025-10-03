def interpolation_search(arr, target):
    low, high = 0, len(arr) - 1

    while low <= high and target >= arr[low] and target <= arr[high]:
        if low == high:
            if arr[low] == target:
                return low
            return -1

        # Estimate the position using interpolation formula
        pos = low + int(((high - low) / (arr[high] - arr[low])) * (target - arr[low]))

        if arr[pos] == target:
            return pos
        elif arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1

    return -1


if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50, 60]
    target = 40
    print("Interpolation Search:", interpolation_search(arr, target))
