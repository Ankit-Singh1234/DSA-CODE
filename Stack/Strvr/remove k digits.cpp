//////////////// best approach ........

/////////////////////     method 1        /////////

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        for( int i=ans.length()-1; i>=0; i--){
            if(ans[i]=='0'){
                ans.pop_back();
            }
            else{
                break;
            }
        }

        reverse(ans.begin(), ans.end());
        if(ans=="") return "0";

      

       

        return ans;
    }
};
////////////////////////////


///////////////////// method 2/////////////

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

      

        reverse(ans.begin(), ans.end());

        while (ans.length() > 1 && ans[0] == '0') {
            ans.erase(ans.begin());
        }

        // int i=0;
        // int len=ans.length();
        // for( i=0; i<len; i++){
        //     if(ans[i]!='0')
        //     break;
        // }

        // ans=ans.substr(i, len-i);
        if (ans == "") return "0";

        return ans;
    }
};

////////////////////////////////////



/////////////////////////  method 3            //////////////////


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

      

        reverse(ans.begin(), ans.end());

        // while (ans.length() > 1 && ans[0] == '0') {
        //     ans.erase(ans.begin());
        // }

        int i=0;
        int len=ans.length();
        for( i=0; i<len; i++){
            if(ans[i]!='0')
            break;
        }

        ans=ans.substr(i, len-i);
          if (ans == "") return "0";

        return ans;
    }
};