class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n=nums.size();
        int l=0, r=0, maxLen=0, zeros=0;

        while(r<n){

             if(nums[r]==0){   // this code uppar hi rahega else it gives wrong answer
                zeros++;
            }


            while( zeros>k){
                // check if at l is 0
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }

           
            maxLen=max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
        
    }
};