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
vector<int> chd[MAXN];

int tt = 1;
int in[MAXN], out[MAXN];
int x[MAXN];
int id = 1;
int sz[MAXN];
int ans = 0;
bool dp[MAXN];

void dfs1(int i, int fa) {
    for (auto it: G[i]) if (it != fa) {
        dfs1(it, i);
        sz[i] += sz[it];
        chd[i].pb(sz[it]);
    }
    sz[i]++;
}

void dfs(int i, int fa) {
    in[i] = tt++;

    pii mx(0, 0);
    int sum = 0;

    for (auto it: G[i]) if (it != fa) {
        dfs(it, i);
        sum += sz[it];
        if (sz[it] >= mx.F) {
            mx.S = mx.F;
            mx.F = sz[it];
        }
        else if (sz[it] > mx.S)
            mx.S = sz[it];
    }

    for (int i = 1; i <= sum / 2; i++)
        dp[i] = false;
    dp[0] = true;
    for (int j = 0; j < chd[i].size(); j++) {
        for (int k = sum / 2 - chd[i][j]; k >= 0; k--) if (dp[k]) {
            dp[k + chd[i][j]] = true;
        }
    }
    for (int j = sum / 2; j >= 0; j--) {
        if (dp[j]) {
            ans += j * (sum - j);
            break;
        }
    }

    // ans += mx.F * mx.S;

    out[i] = tt;
    x[id++] = i;
}

void sol() {
    cin >> n;
    for (int i = 2, a; i <= n; i++) {
        cin >> a;
        G[i].pb(a);
        G[a].pb(i);
    }

    dfs1(1, 1);
    dfs(1, 1);

    // int ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i + 1; j <= n; j++) {
    //         if (!((in[x[i]] <= in[x[j]] && out[x[j]] <= out[x[i]]) || (in[x[j]] <= in[x[i]] && out[x[i]] <= out[x[j]])))
    //             ans++;
    //     }
    // }
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