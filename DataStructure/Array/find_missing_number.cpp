#include <bits/stdc++.h>
using namespace std;

// Method 1: Using Sum Formula
// Time Complexity: O(n), Space Complexity: O(1)
// For array containing numbers from 1 to n+1 with one missing
int findMissingSum(vector<int>& nums) {
    int n = nums.size() + 1; // Total numbers should be n+1
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    
    for (int num : nums) {
        actualSum += num;
    }
    
    return expectedSum - actualSum;
}

// Method 2: Using XOR
// Time Complexity: O(n), Space Complexity: O(1)
// XOR of a number with itself is 0, XOR with 0 is the number itself
int findMissingXOR(vector<int>& nums) {
    int n = nums.size() + 1;
    int xorAll = 0, xorArray = 0;
    
    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }
    
    // XOR all numbers in array
    for (int num : nums) {
        xorArray ^= num;
    }
    
    return xorAll ^ xorArray;
}

// Method 3: Using Hash Set
// Time Complexity: O(n), Space Complexity: O(n)
int findMissingHashSet(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int n = nums.size() + 1;
    
    for (int i = 1; i <= n; i++) {
        if (numSet.find(i) == numSet.end()) {
            return i;
        }
    }
    
    return -1; // Should not reach here for valid input
}

// Method 4: Using Binary Search (for sorted array)
// Time Complexity: O(log n), Space Complexity: O(1)
int findMissingSorted(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // If nums[mid] == mid + 1, missing number is on the right
        if (nums[mid] == mid + 1) {
            left = mid + 1;
        } else {
            // Missing number is on the left or is mid + 1
            right = mid - 1;
        }
    }
    
    return left + 1;
}

// Method 5: Using Cyclic Sort approach
// Time Complexity: O(n), Space Complexity: O(1)
int findMissingCyclicSort(vector<int>& nums) {
    int n = nums.size();
    
    // Place each number at its correct position
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    // Find the first position where number is not at correct place
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1; // All numbers are in place, missing is n+1
}

// Method 6: Find multiple missing numbers in range
vector<int> findAllMissingNumbers(vector<int>& nums, int maxNum) {
    vector<bool> present(maxNum + 1, false);
    vector<int> missing;
    
    // Mark present numbers
    for (int num : nums) {
        if (num >= 1 && num <= maxNum) {
            present[num] = true;
        }
    }
    
    // Find missing numbers
    for (int i = 1; i <= maxNum; i++) {
        if (!present[i]) {
            missing.push_back(i);
        }
    }
    
    return missing;
}

void printVector(vector<int>& arr, string label = "Array") {
    cout << label << ": [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "Find Missing Number Implementations\n" << string(45, '=') << endl;
    
    // Test Case 1: Numbers 1 to 5, missing 3
    vector<int> nums1 = {1, 2, 4, 5};
    cout << "\nTest Case 1:" << endl;
    printVector(nums1, "Input");
    cout << "Expected range: 1 to " << nums1.size() + 1 << endl;
    
    cout << "Method 1 (Sum): " << findMissingSum(nums1) << endl;
    cout << "Method 2 (XOR): " << findMissingXOR(nums1) << endl;
    cout << "Method 3 (Hash Set): " << findMissingHashSet(nums1) << endl;
    
    // Test Case 2: Sorted array for binary search
    vector<int> nums2 = {1, 2, 3, 5, 6, 7};
    cout << "\nTest Case 2 (Sorted):" << endl;
    printVector(nums2, "Input");
    cout << "Method 4 (Binary Search): " << findMissingSorted(nums2) << endl;
    
    // Test Case 3: Cyclic sort approach
    vector<int> nums3 = {4, 1, 2}; // Missing 3
    cout << "\nTest Case 3 (Cyclic Sort):" << endl;
    vector<int> nums3_copy = nums3; // Keep original for display
    printVector(nums3_copy, "Input");
    cout << "Method 5 (Cyclic Sort): " << findMissingCyclicSort(nums3) << endl;
    
    // Test Case 4: Multiple missing numbers
    vector<int> nums4 = {1, 3, 6, 7, 9};
    int maxNum = 10;
    cout << "\nTest Case 4 (Multiple Missing):" << endl;
    printVector(nums4, "Input");
    cout << "Range: 1 to " << maxNum << endl;
    vector<int> allMissing = findAllMissingNumbers(nums4, maxNum);
    printVector(allMissing, "Missing numbers");
    
    // Test Case 5: Edge case - missing first number
    vector<int> nums5 = {2, 3, 4, 5};
    cout << "\nTest Case 5 (Missing first):" << endl;
    printVector(nums5, "Input");
    cout << "Missing number (Sum): " << findMissingSum(nums5) << endl;
    
    // Test Case 6: Edge case - missing last number
    vector<int> nums6 = {1, 2, 3, 4};
    cout << "\nTest Case 6 (Missing last):" << endl;
    printVector(nums6, "Input");
    cout << "Missing number (Sum): " << findMissingSum(nums6) << endl;
    
    return 0;
}
