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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 500005 
int n, m, st;
vector<int> G[MAXN];
int cnt[MAXN];
int dep[MAXN];
pii E[MAXM];
bitset<MAXN> vis;

void sol() {
	cin >> n >> m >> st;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        E[i] = {a, b};
    }

    queue<pii> q;
    q.push({st, 1});
    vis[st] = 1;
    int mx = 0;
    int ans = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        ans += cnt[u.S];
        cnt[u.S]++;
        dep[u.F] = u.S;
        cmax(mx, u.S);

        for (int v : G[u.F]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push({v, u.S + 1});
            }
        }
    }
    for (int i = mx; i; i--) {
        // ans += (cnt[i] - 1) * (cnt[i]) / 2;
        ans += cnt[i] * cnt[i - 1];
    }

    for (int i = 0; i < m; i++) {
        if (abs(dep[E[i].F] - dep[E[i].S]) <= 1) {
            ans--;
        }
    }

    cout << ans << endl;
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