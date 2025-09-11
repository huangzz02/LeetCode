#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int max = 0, len = flowerbed.size();
        for (int i = 0; i < len; i++) {
            if (flowerbed[i] == 0) {
                if (len == 1) {
                    flowerbed[0] = 1;
                    max++;
                } else {
                    if (i == 0 && flowerbed[i + 1] == 0){
                        flowerbed[0] = 1;
                        max++;
                    } else if (i == len - 1 && flowerbed[i - 1] == 0){
                        flowerbed[len - 1] = 1;
                        max++;
                    } else if (i != 0 && i != len - 1 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        max++;
                    }
                }
            }
        }

        return max >= n;
    }
};

int main() {
    Solution sol;
    vector<int> flowerbed = {0,1,0};
    int n = 1;
    cout << (sol.canPlaceFlowers(flowerbed, n) ? "true" : "false") << endl;
    return 0;
}