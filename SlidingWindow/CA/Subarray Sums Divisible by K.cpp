class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n=nums.size();
        int preSum=0;
        int tot=0;
        int rem=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;

        for( int i=0; i<n; i++){

            preSum+=nums[i];
            rem=preSum%k;
            if(rem<0){
                rem=(rem+k)%k;

            }
            if(mpp.count(rem)){
                tot+=mpp[rem];
                mpp[rem]++;
            }
            else{
                mpp[rem]++;
            }



        }


        return tot;
        
    }
};

/*
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n=nums.size();
        int preSum=0;
        int tot=0;
        int preSumRem=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;

        for( int i=0; i<n; i++){

            preSum+=nums[i];
            preSumRem=(preSum%k+k)%k ;
            // if(mpp.count(preSumRem)){
            //     tot+=mpp[preSumRem];
            //     mpp[preSumRem]++;
            // }
            // else{
            //     mpp[preSumRem]++;
            // }

            tot+=mpp[preSumRem];
            mpp[preSumRem]++;



        }


        return tot;
        
    }
};*/