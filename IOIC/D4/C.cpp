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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
int dp[MAXN], dep[MAXN], sub[MAXN], len[MAXN], up[MAXN];
int mn;
bitset<MAXN> vis;

pii take;
int mxlen;

void dfs1(int i) {
    vis[i] = true;

    sub[i] = dep[i];
    dp[i] = dep[i];
    int owo = dep[i];
    for (int e: G[i]) if (!vis[e] && (min(i, e) != take.F || max(i, e) != take.S)) {
        dep[e] = dep[i] + 1;
        cmax(up[e], max(sub[i], dep[i]));
        dfs1(e);
        cmax(mxlen, dp[e] + dp[i] - 2 * dep[i]);
        cmax(owo, dp[e] - dep[i]);
        cmax(owo, dp[i] - dep[i]);
        cmax(sub[i], sub[e]);
    }
    cmin(mn, owo);
    cout << i << ' ' << owo << endl;
}

// void dfs2(int i) {
//     vis[i] = true;

//     for (int e: G[i]) if (!vis[e] && (min(i, e) != take.F || max(i, e) != take.S)) {
//         up[e] = 
//         dfs2(e);

//     }
// }


void sol() {
    cin >> n;

    if (n > 1000)
        return;

    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        // cout << a << ' ' << b << endl;
    }
    // cout << G[1].count(5) << endl;

    // if (n <= 50) {
    //     brute();
    // }
    // return;

    int ans = INF;

    dfs1(1);
    ans = mxlen;

    for (int i = 1; i <= n; i++) {
        for (int it: G[i]) {
            int tmp = 0;
            take = pii(min(i, it), max(i, it));
            MEM(dp, 0);
            MEM(dep, 0);
            MEM(sub, 0);
            MEM(len, 0);
            MEM(up, 0);



            vis.reset();
            mn = INF;
            mxlen = 0;


            dfs1(i);
            tmp += mn;
            // cout << tmp << endl;
            mn = INF;

            dfs1(it);
            tmp += mn + 1;
            cmax(tmp, mxlen);
            cmin(ans, tmp);
            // cout << i << ' ' << it << ' ' << tmp << endl;
        }

        reverse(all(G[i]));

        for (int it: G[i]) {
            int tmp = 0;
            take = pii(min(i, it), max(i, it));
            // MEM(dp, 0);
            // MEM(dep, 0);
            // MEM(sub, 0);
            // MEM(len, 0);



            vis.reset();
            mn = INF;
            mxlen = 0;


            dfs1(i);
            tmp += mn;
            // cout << tmp << endl;
            mn = INF;

            dfs1(it);
            tmp += mn + 1;
            cmax(tmp, mxlen);
            cmin(ans, tmp);
            // cout << i << ' ' << it << ' ' << tmp << endl;
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