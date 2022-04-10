#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[100][100];

int main() {
	int num = 1;
	for (int i = 1; i <= 40; i++) {
		if (i % 2 == 1) {
			for (int x = i, y = 1; x >= 1 && y <= i ; x--, y++) {
				a[x][y] = num++;
			}
		} else {
			for (int x = 1, y = i; x <= i && y >= 1 ; x++, y--) {
				a[x][y] = num++;
			}
		}
	}

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}