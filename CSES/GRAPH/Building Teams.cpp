#pragma region
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
vector<int> v[100005];
int col[100005];
bool vis[100005];
bool dfs(int i, int colar)
{
    vis[i] = 1;
    col[i] = colar;
    bool yes = 1;
    for (int e : v[i])
    {
        if (!vis[e])
        {
            yes &= dfs(e, 1 ^ colar);
        }
        else if (col[i] == col[e])
            yes = 0;
    }
    return yes;
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        MEM(vis, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                ans &= dfs(i, 1);
        }
        if (!ans)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            for (int i = 1; i <= n; i++)
                cout << col[i] + 1 << " ";
            cout << endl;
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
        END
    }
    return 0;
}