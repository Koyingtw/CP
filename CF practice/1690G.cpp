// Problem: F. Shifting String
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define MAXN 205
#define MAXM 1000005 
int n, m;
int x[MAXN];
bitset<MAXN> vis;
vector<int> G[MAXN];

string s;

string f(string i) {
	string tmp = "";
	tmp += i[i.size() - 1];
	tmp += i.substr(0, i.size() - 1);
	// cout << tmp << endl;
	return tmp;
}

int dfs(int i, string p) {
	// cout << i << " " << vis[i] << " " << p << endl;
	if (vis[i]) {
		string tmp = p;
		for (int i = 1; i <= p.size(); i++) {
			tmp = f(tmp);
			if (tmp == p) {
				return i;
			}
		}
	}
	
	p += s[i];
	
	vis[i] = true;
	
	return dfs(G[i][0], p);
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++)
		G[i].clear();
	vis.reset();
	
	cin >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		--x[i];
		
		G[i].pb(x[i]);
	}
	
	int ans = 1;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		string tmp = "";
		// tmp += s[i];
		if (!vis[i]) {
			int owo = dfs(i, tmp);
			v.pb(owo);
			// cout << ans << " ";
		}
	}
	for (int i = 1; i < v.size(); i++) {
		v[i] = (v[i] * v[i - 1]) / (__gcd(v[i], v[i - 1]));
	}
		
	cout << v.back() << endl;
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