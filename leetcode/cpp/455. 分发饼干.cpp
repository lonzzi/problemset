#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int q, p;
    q = p = 0;
    int ans = 0;
    for (int i = 0; q < g.size() && p < s.size(); i++) {
        if (g[q] <= s[p]) {
            ans++; q++; p++;
        } else {
            p++;
        }
    }

    return ans;
}

int main() {
    vector<int> g({1, 2, 3});
    vector<int> s({3, 4, 5});

    cout << findContentChildren(g, s) << endl;

    return 0;
}