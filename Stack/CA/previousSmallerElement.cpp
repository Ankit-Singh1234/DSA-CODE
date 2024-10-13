#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> previousSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);  // To store the result
    stack<int> s;           // Stack to store the previous smaller elements

    // Traverse the array from left to right
    for (int i = 0; i < n; i++) {


        // stack mein se dhund kaun smaller hai current se , agar 
        //nahi hai to bahhhhaar nikaaaal deee (⩺_⩹)

        // mujhe stack mein se smaller element chahiye agar jab tak 
        // top bada hai to  ba ba ba bahar nkal
        // 


        // Pop elements from the stack that are greater than or equal to arr[i]
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If the stack is empty, there is no smaller element
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();  // The top element is the previous smaller element
        }

        // Push the current element into the stack
        s.push(arr[i]);
    }
    
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = previousSmallerElement(arr);

    cout << "Previous smaller elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
