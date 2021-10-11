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
int n, m;
struct node
{
    int x, y, dis;
};
int path[5] = {1, 0, -1, 0, 1};
string pc = "URDL"; //
bool out(int i, int j)
{
    return (i < 0 || j < 0 || i >= n || j >= m);
}

bool vis[1005][1005];
char c[1005][1005];
void sol()
{
    while (cin >> n >> m)
    {
        int dist[n][m];
        int mondis[n][m];
        MEM(dist, 0);
        MEM(vis, 0);
        MEM(mondis, 63);
        pr start, fin;
        queue<node> q;
        queue<node> mon;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
                if (c[i][j] == 'A')
                    start = {i, j};
                if (c[i][j] == 'M')
                {
                    mon.push({i, j, 0});
                    mondis[i][j] = 0;
                }
            }
        while (mon.size())
        {
            node now = mon.front();
            vis[now.x][now.y] = 1;
            mon.pop();
            if (now.dis > mondis[now.x][now.y])
                continue;
            mondis[now.x][now.y] = now.dis;
            for (int i = 0; i < 4; i++)
            {
                if (out(now.x + path[i], now.y + path[i + 1]))
                    continue;
                if (c[now.x + path[i]][now.y + path[i + 1]] != '#' && vis[now.x + path[i]][now.y + path[i + 1]] == 0)
                {
                    vis[now.x + path[i]][now.y + path[i + 1]] = 1;
                    mon.push({now.x + path[i], now.y + path[i + 1], now.dis + 1});
                }
            }
        }
        MEM(vis, 0);
        bool yes = 0;
        q.push({start.F, start.S, 0});
        while (q.size() && !yes)
        {
            node now = q.front();
            q.pop();
            if (mondis[now.x][now.y] <= now.dis)
                continue;
            vis[now.x][now.y] = 1;
            dist[now.x][now.y] = now.dis;
            for (int i = 0; i < 4; i++)
            {

                if (out(now.x + path[i], now.y + path[i + 1]))
                {
                    yes = 1;
                    fin = {now.x, now.y};
                    break;
                }
                if (c[now.x + path[i]][now.y + path[i + 1]] == '.' && vis[now.x + path[i]][now.y + path[i + 1]] == 0)
                {
                    q.push({now.x + path[i], now.y + path[i + 1], now.dis + 1});
                    vis[now.x + path[i]][now.y + path[i + 1]] = 1;
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //         cout << dist[i][j] << " ";
        //     cout << endl;
        // }
        if (yes == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        stack<char> ans;
        int qq = dist[fin.F][fin.S] - 1;
        pr now = fin;
        for (int i = 0; i < qq; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (out(now.F + path[j], now.S + path[j + 1]) == 0 && dist[now.F + path[j]][now.S + path[j + 1]] == dist[now.F][now.S] - 1 && (c[now.F + path[j]][now.S + path[j + 1]] == '.' || c[now.F + path[j]][now.S + path[j + 1]] == 'A'))
                {

                    now = {now.F + path[j], now.S + path[j + 1]};
                    ans.push(pc[j]);

                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (out(now.F + path[i], now.S + path[i + 1]))
                continue;
            if (now.F + path[i] == start.F && now.S + path[i + 1] == start.S)
                ans.push(pc[i]);
        }
        cout << "YES\n"
             << ans.size() << endl;
        while (ans.size())
        {
            cout << ans.top();
            ans.pop();
        }
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
    }
    return 0;
}