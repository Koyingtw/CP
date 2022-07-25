// Problem: E. Price Maximization
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/E
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int cnt[1005];



void sol() {
	cin >> n >> m;
	int sum = 0;
	
	MEM(cnt, 0);
	
	int owo = 0;
	
	for (int i = 0; i < n; i++)	{
		cin >> x[i];
		sum += x[i] / m;
		cnt[x[i] % m]++;
	}

	
	for (int i = 1; i < m; i++) {
		for (int j = m - 1; j >= m - i && cnt[i]; j--) {
			int owo = min(cnt[i], cnt[j]);
			if (i == j)
				owo = cnt[i] / 2;
			cnt[i] -= owo;
			cnt[j] -= owo;
			sum += owo;
		}
	}
	
	// if (m % 2 == 0)
		// sum += (cnt[m / 2] + r) / 2;
	// for (int i = 1; i < k; i++) {
	// }
	cout << sum << endl;
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