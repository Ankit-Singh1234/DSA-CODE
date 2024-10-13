// #include <iostream>
// #include <vector>
// using namespace std;
// /*
// //////////////////////////////////
// */


// class Solution {
//   public:
//     vector<int> makeBeautiful(vector<int> arr) {
        
//       stack<int>st;
      
//       for(int i=0; i<arr.size(); i++){
          
//           if(st.empty()){
//           st.push(arr[i]);
//       }
      
//       else if(arr[i]>=0){
//           if(st.top()>=0){
//               st.push(arr[i]);
//           }
//           else{
//               st.pop();
//           }
//       }
//       else{
//           if(st.top()<0){
//               st.push(arr[i]);
//           }
//           else{
//               st.pop();
//           }
//       }
      
//       }
      
      
//     vector<int> ans(st.size());
//     // Pre-allocate the vector with the size of the stack
//     // int i=st.size()-1;
//     // while(!st.empty()){
//     //     ans[i]=st.top();
//     //     i--;
//     //     st.pop();
//     // }
    
    
//     // return ans;
    
    
//       int i=0;
//       while(!st.empty()){
//           ans[i]=st.top();
//           st.pop();
//           i++;
//       }
      
//       reverse(ans.begin(), ans.end());
      
//       return ans;
        
        
//         // code here
//     }
// };


//////////////////////////////////////////

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> makeBeautiful(vector<int>& arr) {
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        if (!st.empty() && ((st.top() >= 0 && arr[i] < 0) || (st.top() < 0 && arr[i] >= 0))) {
            st.pop();
        } else {
            st.push(arr[i]);
        }
    }
    
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = makeBeautiful(arr);
    
    if (result.empty()) {
        cout << "[]";
    } else {
        for (int num : result) {
            cout << num << " ";
        }
    }
    
    return 0;
}




/*
//////////////////////////////////////////////

*/



// // Function to make the array beautiful by removing adjacent elements with different signs
// vector<int> makeBeautiful(vector<int>& arr) {
//     // Create an empty stack (we use a vector as a stack)
//     vector<int> stack; 
    
//     // Loop through each element in the input array
//     for (int i = 0; i < arr.size(); i++) {
//         // If the stack is not empty, we check if the current element and the top of the stack
//         // have different signs. If one is negative and the other is non-negative, we remove the top element.
//         if (!stack.empty() && ((stack.back() >= 0 && arr[i] < 0) || (stack.back() < 0 && arr[i] >= 0))) {
//             // The top of the stack and current element have different signs, so we pop the top of the stack.
//             stack.pop_back();
//         } else {
//             // If the current element and the top of the stack have the same sign (both non-negative or both negative),
//             // or if the stack is empty, we push the current element onto the stack.
//             stack.push_back(arr[i]);
//         }
//     }
    
//     // After the loop, the stack will contain the "beautiful" array where adjacent elements have the same sign.
//     return stack;
// }

// int main() {
//     // Test Case 1:
//     vector<int> arr1 = {4, 2, -2, 1}; // Input array
//     cout << "Input: ";
//     for (int num : arr1) {
//         cout << num << " ";
//     }
//     cout << endl;
    
//     // Call the function to make the array beautiful
//     vector<int> result1 = makeBeautiful(arr1);
    
//     // Output the result for Test Case 1
//     cout << "Output: ";
//     if (result1.empty()) {
//         cout << "[]"; // If the array is empty, print an empty array
//     } else {
//         for (int num : result1) {
//             cout << num << " ";
//         }
//     }
//     cout << endl;
    
//     // Test Case 2:
//     vector<int> arr2 = {2, -2, 1, -1}; // Input array
//     cout << "Input: ";
//     for (int num : arr2) {
//         cout << num << " ";
//     }
//     cout << endl;
    
//     // Call the function to make the array beautiful
//     vector<int> result2 = makeBeautiful(arr2);
    
//     // Output the result for Test Case 2
//     cout << "Output: ";
//     if (result2.empty()) {
//         cout << "[]"; // If the array is empty, print an empty array
//     } else {
//         for (int num : result2) {
//             cout << num << " ";
//         }
//     }
//     cout << endl;
    
//     return 0;
// }
