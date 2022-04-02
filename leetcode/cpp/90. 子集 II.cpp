#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> t;

void dfs(int startIndex, vector<int> nums) {
    if (t.size() == nums.size()) {
        return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
        if (i > startIndex && nums[i] == nums[i-1]) {
            continue;
        }
        t.push_back(nums[i]);
        ans.push_back(t);
        dfs(i+1, nums);
        t.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    dfs(0, nums);
    return ans;
}

int main() {
    vector<int> nums({1, 2, 2});
    vector<vector<int>> ret = subsetsWithDup(nums);
    
}