#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int countSubstringsBetter(const string& s) {
    int n = s.length();
    int count = 0;
    int left = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        // Shrink the window until we no longer have all 3 characters.
        while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
            count += n - right; // Add all substrings ending at 'right'.
            freq[s[left]]--;
            left++;
        }
    }
    return count;
}

int main() {
    string s = "abcabc";
    cout << "Better Approach: " << countSubstringsBetter(s) << endl;
    return 0;
}
