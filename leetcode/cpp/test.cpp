#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<ll> w;
vector<ll> path;
set<ll> ans;

void dfs(int startIndex, char ch) {
	if (path.size() == w.size()) {
		return;
	}
	for (int i = startIndex; i < w.size(); i++) {
		if (path.size() == 0) {
			path.push_back(w[i]);
		} else if (ch == '+') {
			path[0] += w[i];
		} else if (ch == '-') {
			path[0] -= w[i];
		}
        if (path[0] > 0) {
			ans.insert(path[0]);
		}

		dfs(i + 1, '+');
		dfs(i + 1, '-');

		if (ch == '+') {
			path[0] -= w[i];
		}
		if (ch == '-') {
			path[0] += w[i];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll temp = 0;
		cin >> temp;
		w.push_back(temp);
	}

	dfs(0, '+');
	dfs(0, '-');

	cout << ans.size() << endl;

	return 0;
}