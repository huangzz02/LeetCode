#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        // Add padding zeros to both ends to avoid boundary checks
        int len = flowerbed.size();

        for (int i = 1; i < len - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) return true;  // Early exit if done
            }
        }
        return n <= 0;
    }
};

int main() {
    Solution sol;
    vector<int> flowerbed = {0,1,0};
    int n = 1;
    cout << (sol.canPlaceFlowers(flowerbed, n) ? "true" : "false") << endl;
    return 0;
}
