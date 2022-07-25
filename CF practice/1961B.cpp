// Problem: B. Shoe Shuffling
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
pii x[MAXN];

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i].F;
		x[i].S = i;
	}
	sort(x, x + n);
	int l = 0;
	for (int i = 1; i < n; i++) {
		if (x[i].F != x[i - 1].F) {
			pii tmp = x[l];
			int len = i - l;
			for (int j = 0; j < len ; j++) {
				pii owo = x[l + (j + 1) % len];
				x[l + (j + 1) % len] = tmp;
				tmp = owo;
			}
			l = i;
		}
	}
	if (l != n - 1) {
		pii tmp = x[l];
		int len = n - l;
		for (int j = 0; j < len; j++) {
			pii owo = x[l + (j + 1) % len];
			x[l + (j + 1) % len] = tmp;
			tmp = owo;
		}
	}
	bool yes = 1;
	for (int i = 0; i < n; i++) {
		yes &= (x[i].S != i);
	}
	if (yes) {
		for (int i = 0; i < n; i++)
			cout << x[i].S + 1 << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}