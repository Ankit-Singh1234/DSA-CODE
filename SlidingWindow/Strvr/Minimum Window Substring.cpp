class Solution {
public:
    string minWindow(string s, string t) {

        int rc=t.length();
        int l=0;
        int minLen=INT_MAX;
        unordered_map<char, int> freq;
        int start_i=0;

       

        for( int i=0; i<t.length(); i++){
             freq[t[i]]++; // fill the map initially
        }

        for( int r=0; r<s.length(); r++){

            //insertion in freq map

            //first chek is it required char
            if(freq[s[r]]>0){
                rc--;
            }
            freq[s[r]]--;

            while( rc==0){

                //updating minLen
                if(minLen>r-l+1){
                    minLen=r-l+1;
                    start_i=l;
                }
                


                freq[s[l]]++;

                if(freq[s[l]]>0){
                    rc++;
                }
                l++;


            }


        }

        return (minLen==INT_MAX)? "":s.substr(start_i,minLen);
        
    }
};


/*
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> mp;

        // Count the frequency of each character in t
        for (char &ch : t) {
            mp[ch]++;
        }

        int requiredCount = t.length(); // Number of characters we still need to match
        int l = 0, r = 0;               // Sliding window pointers
        int minStart = 0;                // Start index of the minimum window
        int minWindow = INT_MAX;         // Size of the minimum window

        // Traverse the string s with the right pointer
        while (r < n) {
            // If the character in s is required (present in t), reduce the requiredCount
            if (mp[s[r]] > 0) {
                requiredCount--;
            }

            // Decrease the count of the current character in the map
            mp[s[r]]--;

            // Now try to shrink the window from the left while it's valid (i.e., requiredCount == 0)
            while (requiredCount == 0) {
                // Update the minimum window size
                if (minWindow > r - l + 1) {
                    minWindow = r - l + 1;
                    minStart = l;
                }

                // Move the left pointer, and restore the character count
                mp[s[l]]++;

                // If the character at the left pointer is now required, increase requiredCount
                if (mp[s[l]] > 0) {
                    requiredCount++;
                }

                l++;  // Shrink the window from the left
            }

            r++;  // Expand the window from the right
        }

        // Return the minimum window, or an empty string if no valid window exists
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};
*/