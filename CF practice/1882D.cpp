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
vector<int> G[MAXN];
int x[MAXN];
int ans[30][MAXN];
int chd[MAXN];

void dfs1(int mask, int i, int fa, int cnt) {
    // cout << mask << ' ' << i << ' ' << cnt << endl;
    for (auto e: G[i]) if (e != fa) {
        dfs1(mask, e, i, cnt + ((x[i] & mask) != (x[e] & mask)));
        chd[i] += chd[e] + 1;
    }
    ans[__lg(mask)][1] += cnt;
}

void dfs2(int mask, int i, int fa) {
    if (fa != i) {
        if ((x[i] & mask) == (x[fa] & mask))
            ans[__lg(mask)][i] = ans[__lg(mask)][fa];
        else
            ans[__lg(mask)][i] = ans[__lg(mask)][fa] - chd[i] + (n - chd[i] - 1) - 1;
    }
    for (auto e: G[i]) if (e != fa) {
        dfs2(mask, e, i);
    }
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        cin >> x[i];
        chd[i] = 0;
        for (int j = 0; j < 20; j++)
            ans[j][i] = 0;
    }

    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    // cout << (1 & x[3]) << ' ' << (1 & x[2]) << endl;

    for (int i = 0; i < 20; i++) {
        dfs1(1 << i, 1, 1, 0);
        dfs2(1 << i, 1, 1);
        for (int j = 1; j <= n; j++)
            chd[j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < 20; j++)
            sum += (1LL << j) * ans[j][i];
        cout << sum << " \n"[i == n];
    }
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