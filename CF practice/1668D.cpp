// Problem: D. Optimal Partition
// Contest: Codeforces - Codeforces Round #783 (Div. 2)
// URL: https://codeforces.com/contest/1668/problem/D
// Memory Limit: 256 MB
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
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int Bit[MAXN];
pii x[MAXN];

void init() {
	for (int i = 0; i <= n + 1; i++)
		Bit[i] = 0;
}

void update(int i, int val) {
	while (i <= n) {
		Bit[i] += val;
		i += lowbit(i);
	}
}

int query(int i) {
	int sum = 0;
	while (i) {
		sum += Bit[i];
		i -= lowbit(i);
	}
	return sum;
}

void sol() {
	cin >> n;
	init();
	for (int i = 0; i < n; i++) {
		cin >> x[i].F;
		x[i].S = i + 1;
		update(x[i].S, x[i].F);
	}
	sort(x, x + n);
	int ans = n;
	set<int> st;
	st.insert(0);
	st.insert(n + 1);
	for (int i = 0; i < n && x[i].F <= 0; i++) {
		int l = *(--st.lower_bound(x[i].S));
		int r = *st.upper_bound(x[i].S);
		int sum = query(r - 1) - query(l);
		// cout << sum << " ";
		if (sum <= 0) {
			update(x[i].S, -x[i].F);
			ans -= 1 + (x[i].F < 0);
			st.insert(x[i].S);
		}
	}
	
	// for (int it: st) {
		// cout << it << " ";
	// }
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