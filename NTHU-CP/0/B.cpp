#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#pragma GCC target("avx2,tune=native")

#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> p;
set<int> ans;
set<pii> vis;

void dfs(int i, int sum) {
    // if (vis.count(pii(i, sum)))
    //     return;
    ans.insert(sum);
    ans.insert(n / sum);
    // vis.insert(pii(i, sum));
    if (i == p.size() - 1)
        return;
    if (sum * p[i + 1] <= n && !ans.count(sum * p[i + 1]))
        dfs(i + 1, sum * p[i + 1]);
    dfs(i + 1, sum);
}

void sol() {
    cin >> n;
    ans.insert(1);
    ans.insert(n);
    m = n;
    for (int i = 2; i * i <= m && m > 1; i++) {
        while (m % i == 0 && i * i <= m) {
            p.pb(i);
            m /= i;
        }
    }
    dfs(-1, 1);
    string op;
    for (auto &it: ans) {
        op += to_string(it) + " ";
        // cout << it << ' ';
    }
    put(op);
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