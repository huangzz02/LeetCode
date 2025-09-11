#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int largest = 0;
        for (int i : candies) {
            if (i > largest) largest = i;
        }

        vector<bool> ans;
        for (int i = 0; i < candies.size(); i++) {
            ans.push_back(candies[i] + extraCandies >= largest);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);
    for (bool b : result) {
        cout << (b ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}