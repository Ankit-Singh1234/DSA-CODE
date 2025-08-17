class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";               // Initialize empty answer
        sort(v.begin(),v.end());     // Sort the array of strings
        int n=v.size();              
        string first=v[0], last=v[n-1];  // Take the first and last strings after sorting

        for(int i=0;i<min(first.size(),last.size());i++){  // Compare character by character
            if(first[i]!=last[i]){
                return ans;          // Stop if characters differ
            }
            ans+=first[i];           // Add matching character to answer
        }
        return ans;                  // Return the final common prefix
    }
};

// Why it works for large arrays

// Sorting brings the most different strings to the ends.

// You don’t need to compare every string, only the first and last after sorting.

// Even for hundreds or thousands of strings, this approach only compares two strings fully, making it efficient.
