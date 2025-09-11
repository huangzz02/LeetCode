#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 1. Remove extra spaces (in-place) ("  hello world!  " -> "hello world!")
        int n = s.size();
        int slow = 0; // Slow pointer: position to place the next character
        
        for (int fast = 0; fast < n; ++fast) {
            if (s[fast] != ' ') {
                // Found the start of a word
                if (slow != 0) s[slow++] = ' '; // Add a space between words (if not the first word)
                
                // Copy the whole word
                while (fast < n && s[fast] != ' ') {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        s.resize(slow); // Resize the string

        /*
            example:

            a.  "  hello world!  " s = 0, f = 0
                 ^
                 s,f

            b.  "  hello world!  " s = 0, f = 1
                 ^^
                 sf

            c.  "  hello world!  " s = 0, f = 2
                 ^ ^
                 s f
              ->"h hello world!  "                (s[f] != ' ', s[slow] = s[fast])

            e.  "h hello world!  " s = 1, f = 3
                  ^ ^
                  s f
              ->"hehello world!  "                (s[f] != ' ', s[slow] = s[fast])

            f.  "hehello world!  " s = 2, f = 4
                   ^ ^
                   s f
              ->"helello world!  "                (s[f] != ' ', s[slow] = s[fast])

            g.  "hehello world!  " s = 3, f = 5
                    ^ ^
                    s f
              ->"hellllo world!  "                (s[f] != ' ', s[slow] = s[fast])

            h.  "hehello world!  " s = 4, f = 6
                     ^ ^
                     s f
              ->"hellolo world!  "                (s[f] != ' ', s[slow] = s[fast])

            i.  "hellolo world!  " s = 5, f = 7
                      ^ ^
                      s f

            j.  "hellolo world!  " s = 5, f = 8
                      ^  ^
                      s  f
              ->"hello o world!  " s = 6, f = 8   (s[slow++] = ' ')
                       ^ ^
                       s f
              ->"hello w world!  "                (s[f] != ' ', s[slow] = s[fast])

            k.  "hello w world!  " s = 7, f = 9
                        ^ ^
                        s f
              ->"hello woworld!  "                (s[f] != ' ', s[slow] = s[fast])

            l.  "hello woworld!  " s = 8, f = 10
                         ^ ^
                         s f
              ->"hello wororld!  "                (s[f] != ' ', s[slow] = s[fast])

            m.  "hello wororld!  " s = 9, f = 11
                          ^ ^
                          s f
              ->"hello worlrld!  "                (s[f] != ' ', s[slow] = s[fast])

            n.  "hello worlrld!  " s = 10, f = 12
                           ^ ^
                           s f
              ->"hello worldld!  "                (s[f] != ' ', s[slow] = s[fast])

            o.  "hello worldld!  " s = 11, f = 13
                            ^ ^
                            s f
              ->"hello world!d!  "                (s[f] != ' ', s[slow] = s[fast])

            p.  "hello world!d!  " s = 12, f = 14
                             ^ ^
                             s f

            q.  "hello world!d!  " s = 12, f = 15
                             ^  ^
                             s  f

            r.  "hello world!"                    (s.resize(slow))
        */
        
        // 2. Reverse the entire string ("hello world!" -> "!dlrow olleh")
        reverse(s.begin(), s.end());
        
        // 3. Reverse each word ("!dlrow olleh" -> "world! hello")
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        
        return s;
    }
};

int main() {
    Solution sol;
    string s = "  hello world!  ";
    cout << "\"" << sol.reverseWords(s) << "\"" << endl; // Output: "world! hello"
    return 0;
}