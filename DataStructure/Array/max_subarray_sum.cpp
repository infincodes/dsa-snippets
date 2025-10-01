#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm - Find maximum sum of contiguous subarray
// Time Complexity: O(n), Space Complexity: O(1)
int maxSubarraySum(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        // Either extend the existing subarray or start a new one
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

// Modified Kadane's Algorithm to also return the subarray indices
// Time Complexity: O(n), Space Complexity: O(1)
struct SubarrayResult {
    int maxSum;
    int startIndex;
    int endIndex;
};

SubarrayResult maxSubarrayWithIndices(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0, end = 0, tempStart = 0;
    
    for (int i = 1; i < nums.size(); i++) {
        if (currentSum < 0) {
            currentSum = nums[i];
            tempStart = i;
        } else {
            currentSum += nums[i];
        }
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }
    
    return {maxSum, start, end};
}

// Brute Force Approach (for comparison)
// Time Complexity: O(n³), Space Complexity: O(1)
int maxSubarrayBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += nums[k];
            }
            maxSum = max(maxSum, currentSum);
        }
    }
    
    return maxSum;
}

// Optimized Brute Force
// Time Complexity: O(n²), Space Complexity: O(1)
int maxSubarrayOptimizedBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            maxSum = max(maxSum, currentSum);
        }
    }
    
    return maxSum;
}

void printArray(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

void printSubarray(vector<int>& arr, int start, int end) {
    cout << "[";
    for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i < end) cout << ", ";
    }
    cout << "]";
}

int main() {
    // Test case 1: Mixed positive and negative numbers
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test Case 1:" << endl;
    cout << "Array: ";
    printArray(nums1);
    cout << endl;
    
    int result1 = maxSubarraySum(nums1);
    cout << "Maximum subarray sum (Kadane's): " << result1 << endl;
    
    SubarrayResult detailed1 = maxSubarrayWithIndices(nums1);
    cout << "Maximum subarray: ";
    printSubarray(nums1, detailed1.startIndex, detailed1.endIndex);
    cout << " with sum: " << detailed1.maxSum << endl;
    
    cout << "Brute Force result: " << maxSubarrayBruteForce(nums1) << endl;
    cout << "Optimized Brute Force result: " << maxSubarrayOptimizedBruteForce(nums1) << endl;
    
    cout << "\n" << string(50, '-') << "\n" << endl;
    
    // Test case 2: All negative numbers
    vector<int> nums2 = {-5, -2, -8, -1, -4};
    cout << "Test Case 2 (All negative):" << endl;
    cout << "Array: ";
    printArray(nums2);
    cout << endl;
    
    int result2 = maxSubarraySum(nums2);
    cout << "Maximum subarray sum: " << result2 << endl;
    
    SubarrayResult detailed2 = maxSubarrayWithIndices(nums2);
    cout << "Maximum subarray: ";
    printSubarray(nums2, detailed2.startIndex, detailed2.endIndex);
    cout << " with sum: " << detailed2.maxSum << endl;
    
    cout << "\n" << string(50, '-') << "\n" << endl;
    
    // Test case 3: All positive numbers
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3 (All positive):" << endl;
    cout << "Array: ";
    printArray(nums3);
    cout << endl;
    
    int result3 = maxSubarraySum(nums3);
    cout << "Maximum subarray sum: " << result3 << endl;
    
    SubarrayResult detailed3 = maxSubarrayWithIndices(nums3);
    cout << "Maximum subarray: ";
    printSubarray(nums3, detailed3.startIndex, detailed3.endIndex);
    cout << " with sum: " << detailed3.maxSum << endl;
    
    return 0;
}
