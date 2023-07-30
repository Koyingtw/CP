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
map<int, int> limit[MAXN];
vector<pii> G[MAXN];
bitset<MAXN> vis;

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        limit[a][i] = c;
        for (int j = 0, x; j < b; j++) {
            cin >> x;
            G[x].pb({a, i});
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (limit[i].size() == 0) {
            q.push(i);
            vis[i] = true;
        }

    vector<int> ans;
    while (q.size()) {
        auto now = q.front();
        q.pop();
        ans.pb(now);

        for (auto it: G[now]) if (!vis[it.F]) {
            if (limit[it.F].count(it.S)){
                limit[it.F][it.S]--; 
                if (!limit[it.F][it.S])
                    limit[it.F].erase(it.S);
            }
            if (limit[it.F].size() == 0) {
                vis[it.F] = true;
                q.push(it.F);
            }
        }
    }
    if (ans.size() != n)
        cout << "No" << endl;
    else {
        cout << "Yes" << endl;
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