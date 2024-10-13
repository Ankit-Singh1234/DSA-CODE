#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;




int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    vector<string> strNumbers;
    
    for(int num : numbers) {
        strNumbers.push_back(to_string(num));
    }
    
    sort(strNumbers.begin(), strNumbers.end());

    for(const string& str : strNumbers) {
        cout << str << " ";
    }

    return 0;
}
