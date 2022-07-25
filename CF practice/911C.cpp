// Problem: D. Inversion Counting
// Contest: Codeforces - Educational Codeforces Round 35 (Rated for Div. 2)
// URL: https://codeforces.com/contest/911/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define MAXN 1505
#define MAXM 200005 
int n, m;

struct Fenwick_tree {
	int arr[MAXM];
	
	void init() { for (int i = 0; i < MAXM; i++) arr[i] = 0; }
	
	void update(int i, int val) {
		for (; i < MAXM; i += lowbit(i))
			arr[i] += val;
	}
	
	int query(int i) {
		int res = 0;
		for (; i > 0; i -= lowbit(i))
			res += arr[i];
		
		return res;
	}
} BIT;

void sol() {
	cin >> n;
	BIT.init();
	int ans = 0;
	
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		ans += i - BIT.query(x - 1);
		
		BIT.update(x, 1);
	}
	ans %= 2;

	cin >> m;
	
	int l, r, len;
	while (m--) {
		cin >> l >> r;
		len = r - l + 1;
		len = (len - 1) * len / 2;
		if (len % 2)
			ans ^= 1;
		
		cout << (ans == 1 ? "odd" : "even") << endl;
	}
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