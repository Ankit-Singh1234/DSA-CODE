
#include<map>
int kDistinctChars(int k, string &str)
{
    // Write your code here

    int n=str.length();
    int l=0, r=0, maxLen=0;
    map<char, int>mpp;

    while(r<n){
        // insert
        mpp[str[r]]++;

        //make invalid to valid
        if(mpp.size()>k){

            while(mpp.size()>k){

                mpp[str[l]]--;
                if(mpp[str[l]]==0){
                    mpp.erase(str[l]);
                }
                l++;
            }
        }
        //valid case
        if(mpp.size()<=k){
            maxLen=max(maxLen, r-l+1);
        }

        //increase 'r'
        r++;
        
    }

    return maxLen;
}


