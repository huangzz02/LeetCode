#include <iostream>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        int gcd = std::gcd(str1.length(), str2.length());
        
        // Return the first gcd characters of str1.
        return str1.substr(0, gcd);
    }
};

int main() {
    Solution solution;
    string str1 = "ABCABCABC";
    string str2 = "ABC";
    cout << solution.gcdOfStrings(str1, str2) << endl; // Output: "ABC"
    return 0;
}