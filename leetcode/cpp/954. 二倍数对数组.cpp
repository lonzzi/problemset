#include <bits/stdc++.h>

using namespace std;

bool canReorderDoubled(vector<int>& arr) {
    unordered_map<int, int> cnt;
    for (auto i : arr) {
        cnt[i]++;
    }
    sort(arr.begin(), arr.end(), [](int i, int j) {
        return abs(i) < abs(j);
    });
    for (auto &i : arr) {
        if (cnt[i] != 0 && cnt.find(2 * i) != cnt.end()) {
            cnt[i]--;
            cnt[2 * i]--;
        }
    }
    for (auto &kv : cnt) {
        if (kv.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr({2,1,2,1,1,1,2,2});
    cout << canReorderDoubled(arr) << endl;

    return 0;
}