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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
bitset<MAXN> vis;
int cnt = 0;
int col[MAXN];
int c1 = 0, c2 = 0;
int ans = 0;
int tmp = 0;
bool legal;

struct Disjoint_Set {
    int arr[MAXN << 1], cnt[MAXN << 1];
    Disjoint_Set() {
        for (int i = 1; i < MAXN * 2; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return;
        if (cnt[j] > cnt[i])
            swap(i, j);
        arr[j] = i;
        cnt[i] += cnt[j];
    }
} dsu;

void dfs(int i, int dep) {
    vis[i] = true;
    cnt++;
    col[i] = dep % 2;
    if (col[i] == 0)
        c1++;
    else
        c2++;
    for (int e: G[i]) {
        tmp++;
        if (col[e] == col[i])
            legal = false;
        if (!vis[e]) {
            dfs(e, dep + 1);
        }
    }
}

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        dsu.unite(a, b + n);
        dsu.unite(a + n, b);
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<int> v;
    MEM(col, -0x3f);
    int vsum = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        cnt = c1 = c2 = tmp = 0;
        legal = true;
        dfs(i, 0);
        if (legal) {
            // cout << c1 << ' ' << c2 << ' ' << tmp << endl;
            ans += cnt * vsum;
            vsum += cnt;
            ans += c1 * c2;
            // ans += c2 * (c1 - 1) / 2;
            ans -= tmp / 2;
        }
        else {
            cout << 0 << endl;
            return;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << col[i] << endl;
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