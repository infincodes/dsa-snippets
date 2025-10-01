#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {3, 2, 9, 3, 7, 2, 1};

    for (int i = 0; i < nums.size() ; i++) {
       int minIndex =i;
       for(int j=i+1;j<nums.size();j++)
       {
        if(nums[j]<nums[minIndex])
        {
            minIndex=j;
        }
       }
       swap(nums[minIndex],nums[i]);
    }

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
