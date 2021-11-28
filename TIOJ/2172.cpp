#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#if !LOCAL
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
#define push_back emplace_back
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
int n, q;
vector<int> v[MAXN];
int ac[(int)(log2(MAXN)) + 1][MAXN], L = log2(MAXN);
int up[MAXN], down[MAXN], dep[MAXN], timestamp = 0;
bitset<MAXN> vis;

void dfs(int i, int fa)
{
    ac[0][i] = fa;
    down[i] = timestamp++;
    vis[i] = 1;
    dep[i] = dep[fa] + 1;
    for (int e : v[i])
        if (!vis[e])
            dfs(e, i);
    up[i] = timestamp++;
}

bool isac(int a, int b)
{
    return (down[a] <= down[b] && up[b] <= up[a]);
}
int mn = INF;
void build()
{
    dfs(0, 0);
    for (int i = 1; i <= L; i++)
        for (int j = 0; j < n; j++)
            ac[i][j] = ac[i - 1][ac[i - 1][j]];
}

int LCA(int a, int b)
{
    if (dep[a] > dep[b])
        swap(a, b);
    if ((down[a] <= down[b] && up[b] <= up[a]))
        return a;
    for (int i = L; i >= 0; i--)
    {
        if (!(down[ac[i][a]] <= down[b] && up[b] <= up[ac[i][a]]))
            a = ac[i][a];
    }
    return ac[0][a];
}
void sol()
{
    while (cin >> n >> q)
    {
        L = log2(n);
        for (register int i = 1, a, b; i < n; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        build();

        int a, b, lca;
        while (q--)
        {
            cin >> a >> b;
            lca = LCA(a, b);
            cout << dep[a] + dep[b] - 2 * dep[lca] << endl;
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    // while (cin >> t)
    while (t--)
    {
        sol();
    }
    return 0;
}