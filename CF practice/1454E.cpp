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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
set<int> G[MAXN];
int val[MAXN];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        val[i] = 1;
    }

    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (G[i].size() == 1) {
        q.push(i);
    }

    while (q.size()) {
        auto now = q.front();
        q.pop();

        auto chd = *G[now].begin();
        val[chd] += val[now];
        val[now] = 0;

        for (int e: G[now])
            G[e].erase(now);
        G[now].clear();

        if (G[chd].size() == 1)
            q.push(chd);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += val[i] * (val[i] - 1) / 2;
        ans += val[i] * (n - val[i]);
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