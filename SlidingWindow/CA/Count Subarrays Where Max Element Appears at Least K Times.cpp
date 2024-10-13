class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
         int n=nums.size();
        int l=0; 
        long long cnt=0;

        int frqMxE=0;

        int maxE=*max_element(nums.begin(),nums.end());

        for(int r=0; r<n ;r++){

            if(nums[r]==maxE){
                frqMxE++;
            }

            while(frqMxE==k){

                cnt+=n-r;   //IMPORATNT STEP
                if(nums[l]==maxE){
                    frqMxE--;
                }
                l++;

            }
        }

        return cnt;
        
    }
};

/*
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0; 
        long long cnt=0;

        int maxE=*max_element(nums.begin(),nums.end());

        unordered_map<int,int>freq;

        for( int r=0; r<n; r++){

            freq[nums[r]]++;

            while(nums[r]==maxE && freq[nums[r]]==k){
                cnt+=n-r;
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }

                l++;
            }
        }

        return cnt;
        
    }
};*/