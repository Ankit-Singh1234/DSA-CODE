#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
https://youtu.be/gqXU1UyA8pk?si=sKomEEludGjxziH_


NeetCode
*/

int characterReplacementOptimal(string s, int k) {
    unordered_map<char, int> countMap; // Map to count frequency of characters
    int maxLength = 0; // Variable to store the maximum length of valid substring
    int maxCount = 0; // Variable to store the maximum frequency of a character in the current window
    int left = 0; // Left pointer of the sliding window

    for (int right = 0; right < s.length(); right++) {
        countMap[s[right]]++; // Include current character in the window
        maxCount = max(maxCount, countMap[s[right]]); // Update maxCount

        // Check if we need to shrink the window

        // windowLen-maxRepeatedNumInWindow >k
        while (right - left + 1 - maxCount > k) {
            countMap[s[left]]--; // Decrease the count of the character at the left pointer
            left++; // Move the left pointer to the right
        }

        // Update the maximum length of the valid substring
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s = "AABABBA";
    int k = 1;
    int result = characterReplacementOptimal(s, k);
    cout << "Longest length (Optimal): " << result << endl;
    return 0;
}
