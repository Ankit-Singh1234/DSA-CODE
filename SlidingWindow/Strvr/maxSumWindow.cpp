/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumSlidingWindow(const vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) {
        cout << "Invalid: k is greater than the size of the array" << endl;
        return -1;
    }

    int maxSum = INT_MIN;  // To store the maximum sum
    int windowSum = 0;     // To store the current window sum
    
    // Compute the sum of the first window (first k elements)
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    maxSum = windowSum;  // Initialize maxSum with the sum of the first window

    // Slide the window from the second element onwards
    for (int i = k; i < n; i++) {
        windowSum += nums[i] - nums[i - k];  // Slide the window by adding one element and removing one
        maxSum = max(maxSum, windowSum);     // Update maxSum if the current window sum is larger
    }



       // int Sum=windowSum;
    // int maxSum=nums[0];
    // int l=0;
    // int r=k;
    // while(r<n){
    //     Sum=maxSum-nums[l];
    //     l--;
    //     Sum=maxSum+nums[r];
    //     r++;

    //     maxSum=max(maxSum,Sum);

        
        
    // }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 3, 2, 5, 8, 7, 2, 6};
    int k = 3;
    cout << "Maximum sum of a sliding window of size " << k << " is: " << maxSumSlidingWindow(nums, k) << endl;
    return 0;
}

*/



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumSlidingWindow(const vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) {
        cout << "Invalid: k is greater than the size of the array" << endl;
        return -1;
    }

    // Compute the sum of the first window (first k elements)
    int windowSum = 0; // To store the current window sum
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum; // Initialize maxSum with the sum of the first window
    int l = 0; // Left index
    int r = k; // Right index

    // Slide the window
    while (r < n) {

        windowSum = windowSum - nums[l++] + nums[r++];
        maxSum = max(maxSum, windowSum);

        // Move the window
        // l++;
        // r++;
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 3, 2, 5, 8, 7, 2, 6};
    int k = 3;
    cout << "Maximum sum of a sliding window of size " << k << " is: " << maxSumSlidingWindow(nums, k) << endl;
    return 0;
}
