def fibonacci_search(arr, target):
    n = len(arr)
    
    # Initialize Fibonacci numbers
    fib2 = 0   # (m-2)'th Fibonacci
    fib1 = 1   # (m-1)'th Fibonacci
    fib = fib1 + fib2  # m'th Fibonacci

    # Find the smallest Fibonacci number >= n
    while fib < n:
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2

    offset = -1

    # While there are elements to be inspected
    while fib > 1:
        # Check index within bounds
        i = min(offset + fib2, n - 1)

        if arr[i] < target:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif arr[i] > target:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return i  # Found target

    # Check last element
    if fib1 and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1

    return -1


if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11]
    target = 7
    print("Fibonacci Search:", fibonacci_search(arr, target))
