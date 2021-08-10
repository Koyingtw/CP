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

set<int> v[200005];
bool vis[200005];

void dfs(int i)
{
    vis[i] = 1;
    cout << i << " ";
    for (int j : v[i])
    {
        if (vis[j] == 0)
        {
            dfs(j);
            cout << i << " ";
        }
    }
}

void sol()
{
    int n;
    while (cin >> n)
    {
        MEM(vis, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].insert(b);
            v[b].insert(a);
        }
        dfs(1);
        cout << endl;
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