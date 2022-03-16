#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int> &nums) {
    int curDiff = 0;
    int preDiff = 0;
    int ans = 1;
    for (int i = 0; i < nums.size()-1; i++) {
        curDiff = nums[i+1] - nums[i];
        if ((curDiff < 0 && preDiff >= 0) || (curDiff > 0 && preDiff <= 0)) {
            ans++;
            preDiff = curDiff;
        }
    }
    return ans;
}

int main() { 
    vector<int> nums({1, 7, 4, 9, 2, 5});
    cout << wiggleMaxLength(nums) << endl;

    return 0;
}