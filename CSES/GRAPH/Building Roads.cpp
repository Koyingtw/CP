#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
bool vis[100005];
vector<int> v[100005];

void dfs(int i)
{
    vis[i] = 1;
    for (int j : v[i])
    {
        if (vis[j] == 0)
            dfs(j);
    }
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            v[a].emplace_back(b);
            v[b].emplace_back(a);
        }
        vector<pr> ans;
        dfs(1);
        for (int i = 2; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
                ans.push_back({i - 1, i});
            }
        }
        cout << ans.size() << endl;
        for (pr i : ans)
            cout << i.F << " " << i.S << endl;
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