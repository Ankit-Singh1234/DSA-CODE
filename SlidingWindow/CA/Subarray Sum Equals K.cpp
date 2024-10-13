/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.*/



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n=nums.size();
        int preSum=0;
        int tot=0;

        unordered_map<int,int>mpp;
        //initialise map
        mpp[0]=1;

        for(int i=0; i<n; i++){

            preSum=preSum+nums[i];

            if(mpp.find(preSum-k)!=mpp.end()){  // mpp.count(preSum-k)
                tot+=mpp[preSum-k];

                mpp[preSum]++;  // in map the preSum will go  not preSum-k
            }
            else{
                mpp[preSum]++;
            }
        }

        return tot;
        
    }
};