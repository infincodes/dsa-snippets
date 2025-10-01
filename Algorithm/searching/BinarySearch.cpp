#include <iostream>
#include <vector>

class BinarySearch {
public:
    static int binarySearchIterative(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target)
                return mid;
            
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    

    static int binarySearchRecursive(const std::vector<int>& arr, int target) {
        return binarySearchRecursiveHelper(arr, target, 0, arr.size() - 1);
    }
    
private:
    static int binarySearchRecursiveHelper(const std::vector<int>& arr, int target, int left, int right) {
        if (left > right)
            return -1;
            
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] > target)
            return binarySearchRecursiveHelper(arr, target, left, mid - 1);
        return binarySearchRecursiveHelper(arr, target, mid + 1, right);
    }
};

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    
    int result = BinarySearch::binarySearchIterative(arr, target);
    if (result != -1)
        std::cout << "Element " << target << " found at index " << result << " using iterative method\n";
    else
        std::cout << "Element " << target << " not present in array\n";
    
    result = BinarySearch::binarySearchRecursive(arr, target);
    if (result != -1)
        std::cout << "Element " << target << " found at index " << result << " using recursive method\n";
    else
        std::cout << "Element " << target << " not present in array\n";
    
    return 0;
}