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
#define endl '\n'
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
int ac[25][MAXN], L = 20;
int dep[MAXN];

void dfs(int i, int fa)
{
    for (int e : v[i])
    {
        if (e == fa)
            continue;
        dep[e] = dep[i] + 1;
        ac[0][e] = i;
        dfs(e, i);
    }
}

int LCA(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    int tmp = dep[a] - dep[b];
    for (int i = L; i >= 0; i--)
    {
        if ((1 << i) & tmp)
            a = ac[i][a];
    }
    if (a == b)
        return a;
    for (int i = L; i >= 0; i--)
    {
        if (ac[i][a] != ac[i][b])
        {
            a = ac[i][a];
            b = ac[i][b];
        }
    }
    return ac[0][a];
}
void sol()
{
    while (cin >> n >> q)
    {
        int a, b;
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        // build();
        dep[0] = 0;
        dfs(0, 0);
        for (int i = 1; i <= L; i++)
            for (int j = 0; j < n; j++)
                ac[i][j] = ac[i - 1][ac[i - 1][j]];
        int lca;
        while (q--)
        {
            cin >> a >> b;
            cout << dep[a] + dep[b] - 2 * dep[LCA(a, b)] << endl;
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