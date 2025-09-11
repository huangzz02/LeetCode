#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        
        int a = len1, b = len2;
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        while(b > 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        int gcd = a;

        vector<int> factors;
        for (int i = 1; i <= sqrt(gcd); i++) {
            if (gcd % i == 0) {
                factors.push_back(i);
                if (i != gcd / i)
                    factors.push_back(gcd / i);
            }
        }
        sort(factors.begin(), factors.end(), greater<int>());

        for (int i : factors) {
            string tmp_word;
            for (int j = 0; j < i; j++) {
                tmp_word += str1[j];
            }

            bool isbreak = false;
            for (int j = 0; j < len1; j++) {
                if (str1[j] != tmp_word[j % i]) {
                    isbreak = true;
                    break;
                }
                if (j < len2) {
                    if (str2[j] != tmp_word[j % i]) {
                        isbreak = true;
                        break;
                    }
                }
            }

            if (isbreak == false) return tmp_word;
        }
        return "";
    }
};

int main() {
    Solution solution;
    string str1 = "ABCABCABC";
    string str2 = "ABC";
    cout << solution.gcdOfStrings(str1, str2) << endl; // Output: "ABC"
    return 0;
}