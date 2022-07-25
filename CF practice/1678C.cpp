// Problem: C. Tokitsukaze and Strange Inequality
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
#define MAXN 5005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Bit {
	int arr[MAXN];
	
	void update(int i, int val) {
		while (i < MAXN) {
			arr[i] += val;
			i += lowbit(i);
		}
		return;
	}
	
	int query(int i) {
		int cnt = 0;
		while (i) {
			cnt += arr[i];
			i -= lowbit(i);
		}
		return cnt;
	}
} pre, suf;

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	MEM(pre.arr, 0);
	MEM(suf.arr, 0);
	////
	int ans = 0;
	pre.update(x[0], 1);
	for (int i = 2; i < n; i++)
		suf.update(x[i], 1);
	for (int i = 1; i < n - 2; i++) {
		Bit tmp = suf;
		for (int j = i + 1; j < n - 1; j++) {
			tmp.update(x[j], -1);
			ans += pre.query(x[j]) * (tmp.query(x[i]));
		}
		suf.update(x[i + 1], -1);
		pre.update(x[i], 1);
	}
	
	cout << ans << endl;
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