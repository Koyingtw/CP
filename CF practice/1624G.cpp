// Problem: G. MinOr Tree
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/contest/1624/problem/G
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
int x[MAXN][3];
int dsu[MAXN], cnt[MAXN];

void init() {
	for (int i = 1; i <= n; i++) {
		dsu[i] = i, cnt[i] = 1;
	}
}

int find(int i) {
	return (dsu[i] == i ? i : dsu[i] = find(dsu[i]));
}

bool same(int i, int j) {
	return i == j;
}

void unite(int i, int j) {
	i = find(i), j = find(j);
	if (i == j) return;
	
	if (cnt[i] < cnt[j])
		swap(i, j);
	dsu[j] = i;
	cnt[i] += cnt[j];
}

void sol()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x[i][0] >> x[i][1] >> x[i][2];
	}
	
	int ans = 0;
	int tmp = 0;
	
	for (int i = 30; i >= 0; i--) {
		init();
		int mask = (1 << i) | tmp;
		bool yes = 0;
		for (int i = 0; i < m; i++) {
			if (x[i][2] & mask) continue;
			
			unite(x[i][0], x[i][1]);
		}
		
		if (*max_element(cnt + 1, cnt + n + 1) == n) yes = 1;
		if (yes) {
			tmp |= mask;
		}
	}
	
	for (int i = 0; i < m; i++) {
		if (!(x[i][2] & tmp))
			ans |= x[i][2];
	}
	cout << ans << endl;
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