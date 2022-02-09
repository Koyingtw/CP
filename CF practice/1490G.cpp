// Problem: G. Old Floppy Drive
// Contest: Codeforces - Codeforces Round #702 (Div. 3)
// URL: https://codeforces.com/contest/1490/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN], pre[MAXN], y[MAXN];

void sol()
{
	cin >> n >> m;
	MEM(pre, 0);
	int mx = -INF, sum = 0;
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		pre[i] = pre[i - 1] + x[i];
		sum += x[i];
		cmax(mx, pre[i]);
		if (v.empty() || v[v.size() - 1].F < pre[i]) {
			v.pb({pre[i], i});
		}
	}
	while (m--) {
		int q;
		cin >> q;
		
		if (v.back().F < q && sum <= 0) {
			cout << -1 << " ";
			continue;
		}
		
		int times = 0;
		if (v.back().F < q) {
			times = (q - v.back().F + sum - 1) / sum;
		}
		q -= times * sum;
		cout << times * n + v[lower_bound(v.begin(), v.end(), make_pair(q, 0), less<pii>()) - v.begin()].S - 1 << " ";
	}
	cout << endl;	
		
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}