#pragma region
#include <bits/stdc++.h>
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

bool vis[15];
int n, m, now;
int tmp = INF;

int dfs(vector<pr> v[], int i, int sum, int cnt)
{
    vis[i] = 1;
    if (cnt == n)
    {
        for (pr j : v[i])
        {
            if (j.F == now)
                return sum + j.S;
        }
    }

    for (pr j : v[i])
    {
        if (vis[j.F] == 0)
        {
            tmp = min(dfs(v, j.F, sum + j.S, cnt + 1), tmp);
        }
    }
    vis[i] = 0;
    return tmp;
}

void sol()
{
    while (cin >> n >> m)
    {
        vector<pr> v[n + 1];

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }
        int ans = INF;
        for (int i = 1; i <= n; i++)
        {
            MEM(vis, 0);
            tmp = INF;
            now = i;
            ans = min(ans, dfs(v, i, 0, 1));
        }
        cout << (ans != INF ? ans : -1) << endl;
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