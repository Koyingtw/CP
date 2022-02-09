// Problem: C - The Kth Time Query
// Contest: AtCoder - HHKB Programming Contest 2022（AtCoder Beginner Contest 235）
// URL: https://atcoder.jp/contests/abc235/tasks/abc235_c
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
int x[MAXN];
vector<int> G[MAXN];

void sol()
{
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++)	 {
		cin >> x[i];
		v.pb(x[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(all(v), x[i]) - v.begin();
		G[x[i]].pb(i + 1);
	}
	
	int a, b;
	while (m--) {
		cin >> a >> b;
		if (!binary_search(all(v), a)) {
			cout << -1 << endl;
			continue;
		}
		a = lower_bound(all(v), a) - v.begin();
		if (a == v.size()) {
			cout << -1 << endl;
			continue;
		}
		
		if (G[a].size() < b) {
			cout << -1 << endl;
		}
		else cout << G[a][b - 1] << endl;
		
	}
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}