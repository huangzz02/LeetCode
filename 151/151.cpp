#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> data;
        string tempWord;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                tempWord += s[i];
                if (i + 1 == s.size() || s[i + 1] == ' ') {
                    data.push_back(tempWord);
                    tempWord.clear();
                }
            }
        }

        reverse(data.begin(), data.end());

        string ans;
        for (size_t i = 0; i < data.size(); ++i) {
            ans += data[i];
            if (i < data.size() - 1) ans += " ";
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "  hello world!  ";
    cout << "\"" << sol.reverseWords(s) << "\"" << endl; // Output: "world! hello"
    return 0;
}