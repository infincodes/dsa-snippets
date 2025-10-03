import math

def jump_search(arr, target):
    n = len(arr)
    step = int(math.sqrt(n))  # block size to jump
    prev = 0

    # Jump until the element is greater than or equal to target
    while prev < n and arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    # Linear search in the identified block
    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i

    return -1


if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11]
    target = 9
    print("Jump Search:", jump_search(arr, target))
