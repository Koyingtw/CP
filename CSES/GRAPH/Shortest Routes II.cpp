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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

int dist[505][505];

void sol()
{
    int n, m, q;
    while (cin >> n >> m >> q)
    {
        MEM(dist, 63);
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, dis;
            cin >> a >> b >> dis;
            dist[a][b] = min(dis, dist[a][b]);
            dist[b][a] = min(dis, dist[b][a]);
        }
        for (int t = 1; t <= n; t++)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
                }
        }
        while (q--)
        {
            int a, b;
            cin >> a >> b;

            if (dist[a][b] < dist[0][0])
                cout << dist[a][b] << endl;
            else
                cout << -1 << endl;
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
    }
    return 0;
}