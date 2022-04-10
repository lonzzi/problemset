#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<string> ans;
int maxLen = 0;

bool isValid(string s) {
    int cnt = 0;
    for (auto &ch : s) {
        if (ch == '(') {
            cnt++;
        } else if (ch == ')') {
            cnt--;
            if (cnt < 0) {
                return false;
            }
        }
    }
    if (cnt != 0) {
        return false;
    }
    return true;
}

void traceback(string s, int startIndex, int lremove, int rremove) {
    if (lremove == 0 && rremove == 0) {
        if (isValid(s)) {
            ans.push_back(s);
        }
        return;
    }

    for (int i = startIndex; i < s.size(); i++) {
        if (i != startIndex && s[i] == s[i - 1]) {
            continue;
        }
        if (lremove > 0 && s[i] == '(') {
            traceback(s.substr(0, i) + s.substr(i + 1), i, lremove - 1, rremove);
        }
        if (rremove > 0 && s[i] == ')') {
            traceback(s.substr(0, i) + s.substr(i + 1), i, lremove, rremove - 1);
        }
    }
}

void calRemoveBraket(string s) {
    int lremove = 0, rremove = 0;
    for (auto &ch : s) {
        if (ch == '(') {
            lremove++;
        } else if (ch == ')') {
            if (lremove == 0) {
                rremove++;
            } else {
                lremove--;
            }
        }
    }
    traceback(s, 0, lremove, rremove);
}

vector<string> removeInvalidParentheses(string s) {
    calRemoveBraket(s);
    return ans;
}

int main() {
    vector<string> ret = removeInvalidParentheses(")(f");

    for (auto &str : ret) {
        cout << str << endl;
    }

    return 0;
}