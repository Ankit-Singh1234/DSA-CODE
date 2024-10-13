class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        

        int l=0; 
        int n=nums.size();
        int cnt=0;
        int maxLen=0;
        unordered_map<int,int>freq;

        for( int r=0; r<n ; r++){

            freq[nums[r]]++;

            while(freq[nums[r]]>k){

                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                l++;


            }



            maxLen=max(maxLen, r-l+1);


        }

        return maxLen;
    }
};