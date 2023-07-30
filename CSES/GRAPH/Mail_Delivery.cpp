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
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
set<int> G[MAXN];
vector<int> ans;

void dfs(int i) {
    while (G[i].size()) {
        int tmp = *G[i].begin();
        G[i].erase(tmp);
        G[tmp].erase(i);
        dfs(tmp);
    }
    ans.pb(i);
}

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }

    for (int i = 1; i <= n; i++)
        if (G[i].size() % 2) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

    dfs(1);

    if (ans.size() != m + 1)
        cout << "IMPOSSIBLE" << endl;
    else {
        reverse(all(ans));
        for (auto it: ans)
            cout << it << ' ';
        cout << endl;
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