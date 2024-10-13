#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);  // To store results
    stack<int> s;           // Stack to store next greater elements

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements that are less than or equal to arr[i]


        //mujhe current element ka greater elemnt chahiye , stack mein se dhund ke
        //par agar ka top current current se hi samllae hai to aisa kaise nikalunga 
        // pop out jab tak stack ka top smaller hai current se.



        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If the stack is empty, there is no greater element
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();  // The top element is the next greater element
        }

        // Push the current element into the stack
        s.push(arr[i]);
    }
    
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(arr);

    cout << "Next greater elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
