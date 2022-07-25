// Problem: Cyclic Array
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1191/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
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
#define MAXN 400005
#define MAXM 1000005 
int n, m;
int x[MAXN], pre[MAXN];
int last[MAXN];
int vis[MAXN];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		x[i + n] = x[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		pre[i] = pre[i - 1] + x[i];
	}
	pre[2 * n + 1] = pre[2 * n];
	
	int a = 1, b = 1;
	for (a = 1; a <= 2 * n; a++) {
		while (b <= 2 * n && pre[b + 1] - pre[a - 1] <= m)
			b++;
		last[a] = b + 1;
	}
	
	MEM(vis, 0x3f);
	int ans = INF;
	for (int i = 1; i <= min(last[1], n); i++) {
		int cnt = 0;
		for (int j = i; j < i + n; j = last[j]) {
			cnt++;
			if (vis[j] < cnt) {
				cout << "walked " << j << endl;
				cnt = INF;
				break;
			}
			vis[j] = cnt;
		}
		cmin(ans, cnt);
	}
	cout << ans << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}