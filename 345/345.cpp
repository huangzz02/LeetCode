#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        vector<int> vowel_order;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowels.push_back(s[i]);
                vowel_order.push_back(i);
            }
        }
        reverse(vowels.begin(), vowels.end());

        for (int i = 0; i < vowels.size(); i++) {
            s[vowel_order[i]] = vowels[i];
        }

        return s;
    }
};

int main() {
    Solution sol;
    string s = "hello";
    cout << sol.reverseVowels(s) << endl; // Output: "holle"
    return 0;
}