#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define MEM(x, n) memset(x, n, sizeof(x));
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
int n, m, a, b, c, d;
bool vis[10005][10005];
int px[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int py[8] = {1, -1, -2, -2, -1, 1, 2, 2};
struct data
{
    int x, y, cnt;
};

bool check(int x, int y)
{
    if (x >= 0 && x <= n && y >= 0 && y <= m)
    {
        return vis[x][y] == 0;
    }
    return 0;
}

void sol()
{
    cin >> n >> m >> a >> b >> c >> d;

    for (int i = 0; i <= n; i++)
    {
        MEM(vis[i], 0);
    }
    queue<data> q;
    q.push({a, b, 0});
    while (q.size())
    {
        data now = q.front();
        q.pop();
        if (now.x == c && now.y == d)
        {
            cout << now.cnt << endl;
            break;
        }
        for (int i = 0; i < 8; i++)
        {
            if (check(now.x + px[i], now.y + py[i]))
            {
                q.push({now.x + px[i], now.y + py[i], now.cnt + 1});
                vis[now.x + px[i]][now.y + py[i]] = 1;
            }
        }
        if (q.empty())
        {
            cout << -1 << endl;
            break;
        }
    }
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}