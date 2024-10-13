#include <iostream>
#include <vector>
#include <string>


//searh in hash , jab tak mil raha hai let ko age badha do;
// agar nagi mil raha hai to hash me mark karde ki mil gaya hai right ko badha do



using namespace std; // Use standard namespace

int lengthOfLongestSubstring(const string &s) {
    vector<bool> charPresent(256, false); // Hash vector to store presence of characters (ASCII)
    int maxLength = 0;                      // Variable to store the maximum length of substring
    int left = 0;                           // Left index of the current substring

    for (int right = 0; right < s.length(); ++right) {
        // If the character is already present, remove characters from the left
        while (charPresent[s[right]]) {

            //*********  IMPORTANT step */
            charPresent[s[left]] = false; // Mark the character at the left pointer as not present
            left++;                        // Move the left pointer to the right
        }
        // Mark the current character as present
        charPresent[s[right]] = true;
        // Update maxLength if needed
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength; // Return the maximum length of substring without repeating characters
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}







// #include <iostream>
// #include <set>
// #include <string>

// int lengthOfLongestSubstring(const std::string &s) {
//     std::set<char> charSet; // Set to store characters of the current substring
//     int maxLength = 0;      // Variable to store the maximum length of substring
//     int left = 0;           // Left index of the current substring

//     for (int right = 0; right < s.length(); ++right) {
//         // If the character at right index is already in the set, remove characters from the left
//         while (charSet.find(s[right]) != charSet.end()) {  // end ke barabarv nahi hai iska matlab wo set mein hai
//             charSet.erase(s[left]); // Remove the leftmost character
//             left++;                 // Move the left pointer to the right
//         }
//         // Add the current character to the set
//         charSet.insert(s[right]);
//         // Update maxLength if needed
//         maxLength = std::max(maxLength, right - left + 1);
//     }

//     return maxLength; // Return the maximum length of substring without repeating characters
// }

// int main() {
//     std::string input;
//     std::cout << "Enter a string: ";
//     std::cin >> input;

//     int result = lengthOfLongestSubstring(input);
//     std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;

//     return 0;
// }
