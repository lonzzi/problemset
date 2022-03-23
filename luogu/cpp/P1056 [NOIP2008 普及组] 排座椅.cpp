#include<iostream>
#include <algorithm>
using namespace std;
int n, m, k, l, d;
int x1, x2, ly1, y2;
int b[10001], c[10001];
int b2[10001], c2[10001],a1[10001],a2[10001];
int tot, maxx,ans,ans2;
int main()
{
	cin >> n >> m >> k >> l >> d;
	for (int i = 1; i <= d; i++)
	{
		cin >> x1 >> ly1 >> x2 >> y2;
		if (x1 == x2) b[min(ly1,y2)]++;
		if (ly1 == y2) c[min(x1,x2)]++;
	}

    sort(b, b + d);
    sort(c, c + d);

    for (int i = 0, it = 0; it < k; i++) {
        if (b[i] == 0) {
            continue;
        } else {
            cout << b[i] << " ";
            it++;
        }
    }
    cout << endl;
    for (int i = 0, it = 0; it < l; i++) {
        if (c[i] == 0) {
            continue;
        } else {
            cout << c[i] << " ";
            it++;
        }
    }
}

