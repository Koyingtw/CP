// Problem: C. Dolce Vita
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/C
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
int x[MAXN], pre[MAXN];

void sol() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)	{
		cin >> x[i];
	}
	sort(x, x + n);
	pre[0] = x[0];
	for (int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + x[i];
	
	int ans = upper_bound(pre, pre + n, m) - pre;
	int day = 0;
	for (int i = n - 1; i >= 0; i--) {
		if ((m - pre[i]) / (i + 1) - day > 0) {
			ans += (i + 1) * ((m - pre[i]) / (i + 1) - day);
			day = (m - pre[i]) / (i + 1);
		}
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