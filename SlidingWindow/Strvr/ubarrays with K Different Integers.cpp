// class Solution {
// public:

//     int subarraysWithKDistinctUptoK(vector<int>& nums, int k){

//         int l=0;
//         int sum=0;
//         int cnt=0;
//         int n=nums.size();
//         unordered_map<int,int>mpp;

//         for( int r=0; r<n; r++){
//             // blind add
//             mpp[nums[r]]++;

//             //invalid to valid

//             while(l<=r && cnt>k){
//                 mpp[nums[l]]--;
//                 if(mpp[nums[l]]==0){
//                     mpp.erase(nums[l]);
//                 }
//                 l++;
//             }

//             cnt=cnt+( r-l+1 );
//         }

//         return cnt;



//     }


//     int subarraysWithKDistinct(vector<int>& nums, int k) {
        

//         return subarraysWithKDistinctUptoK(nums,k)-subarraysWithKDistinctUptoK(nums,k-1);
//     }
// };

class Solution {
public:

    int subarraysWithKDistinctUptoK(vector<int>& nums, int k){

        int l=0;
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int>mpp;

        for( int r=0; r<n; r++){
            // blind add
            mpp[nums[r]]++;

            // invalid to valid
            // Here, the condition `cnt > k` is incorrect.
            // It should be checking if the size of the map `mpp.size()` > k,
            // as `cnt` is just the count of subarrays, not the distinct elements.
            while(l<=r && mpp.size() > k){ 
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }

            // Update `cnt` outside the while loop, but after ensuring
            // the window has at most `k` distinct integers.
            cnt += (r - l + 1);
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKDistinctUptoK(nums, k) - subarraysWithKDistinctUptoK(nums, k - 1);
    }
};