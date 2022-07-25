// Problem: F. Array Stabilization (GCD version)
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN << 1];
int ST[20][MAXN << 1];

void build() {
	for (int i = 0; i < 2 * n; i++)
		ST[0][i] = x[i];
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < 2 * n; j++) {
			ST[i][j] = __gcd(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int query(int ql, int qr) {
	int rng = (qr - ql + 1);
	int lg = __lg(rng);
	return __gcd(ST[lg][ql], ST[lg][qr - (1 << lg) + 1]);
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		x[i + n] = x[i];
	}
	build();
	////
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		
		int pre = -1;
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			if (pre == -1)
				pre = query(i, i + mid);
			else 
				yes &= pre == query(i, i + mid);
		}
		
		if (yes)
			r = mid;
		else
			l = mid + 1;
	}
	cout << r << endl;
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