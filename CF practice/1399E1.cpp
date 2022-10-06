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
int sum = 0, ans = 0;
vector<pii> G[MAXN];
bitset<MAXN> vis;
vector<tuple<int, int, int>> E;


struct cmp {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        auto [a1, b1, c1] = a;
        auto [a2, b2, c2] = b;

        if (b1 * c1 - (b1 / 2) * c1 != b2 * c2 - (b2 / 2) * c2)
            return (b1 * c1 - (b1 / 2) * c1 < b2 * c2 - (b2 / 2) * c2);
        else
            return a < b;
    }
};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;

void init() {
    for (int i = 1; i <= n; i++)
        G[i].clear();
    E.clear();
    while (pq.size())
        pq.pop();
    sum = 0, ans = 0;
}

int dfs(int i) {
    vis[i] = 1;

    int res = 0;
    for (auto e: G[i]) {
        if (!vis[e.F]) {
            int tmp = dfs(e.F);
            E.pb({e.S * tmp, e.S, tmp});
            pq.push({e.S * tmp, e.S, tmp});
            sum += e.S * tmp;
            res += tmp;
        }
    }
    return res + (res == 0);
}


void sol() {
    cin >> n >> m;
    init();

    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    vis.reset();
    dfs(1);

    while (sum > m) {
        auto [a, b, c] = pq.top();
        pq.pop();
        // cout << a << ' ' << b << ' ' << c << endl;
        sum -= a;
        b /= 2;
        sum += b * c;
        pq.push({b * c, b, c});
        ans++;
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