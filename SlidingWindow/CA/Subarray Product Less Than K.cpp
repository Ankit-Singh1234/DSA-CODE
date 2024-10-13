class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        

        int prod=1;
        int l=0;
        int cnt=0;

        for(int r=0; r<nums.size();r++){

            // insert
            prod*=nums[r];

            while( l<=r && prod>=k){
                prod=prod/nums[l];
                l++;
            }

            cnt+=r-l+1;
        }

        return cnt;
    }
};