///////////  LEETCODE???????///

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // To store the maximums of each window
        deque<int> dq; // Deque to store indices of useful elements

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // Starting from i = k - 1, we add the maximum for the current window to the result
            if (i >= k - 1) {// window ban gai size k ki , 
                             //to front wla ans mei dal de
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

/////////////////////////////////////////////




