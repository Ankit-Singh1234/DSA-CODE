class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        map<int,int>mpp;
        int l=0, r=0;
        int maxLen=0;
        
         while( r< fruits.size()){

            //insert
            mpp[fruits[r]]++;

            // make valid untill its invalid
            if(mpp.size()>2){

                while(mpp.size()>2){

                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0){
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
            }

            //when condition is valid

            if(mpp.size()<=2){
                maxLen=max(maxLen, r-l+1);
            }

            r++;




         }

         return maxLen;


        
    }
};