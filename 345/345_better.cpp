#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Check if a character is a vowel (case-insensitive)
    bool isVowel(char c) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        return vowels.count(c) > 0; // Return true if c is in vowels set (count(c) -> in: 1, not in: 0)
    }
    
    // Reverse only the vowels in the string
    string reverseVowels(string s) {
        int left = 0; // Left pointer starting from the beginning
        int right = s.size() - 1; // Right pointer starting from the end
        
        while (left < right) {
            // Move left pointer until a vowel is found
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            // Move right pointer until a vowel is found
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            // Swap vowels at left and right pointers
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "hello";
    cout << sol.reverseVowels(s) << endl; // Expected output: "holle"
    return 0;
}