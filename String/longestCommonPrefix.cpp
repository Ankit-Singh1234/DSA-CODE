///Method 1???
class Solution {
public:

    string common(string s1, string s2){
        string temp="";
        int n=min(s1.length(), s2.length());
        for(int i=0; i<n; i++){
            if(s1[i]==s2[i]){
                temp+=s1[i];
            }
            else{
                break;
            }
        }

        return temp;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res=strs[0];
         /*
    Initialize res with the first string: Instead of initializing res to an empty string, it  should start as the first string in the list (res = strs[0]). This ensures that the first string is the initial common prefix.
    */
        for(int i=0; i<n; i++){
            res=common(res, strs[i]);
        }

        return res;
    }

   
};













//// Methoid 2?////

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
