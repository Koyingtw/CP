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
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

int path[5] = {0, 1, 0, -1, 0};

int n;
bool check(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

struct Node
{
    int x, y, tmp, dis;
};

int vis[2][1005][1005];
int x[1005][1005];
void sol()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> x[i][j];
        queue<Node> q, qq;
        int ans = INF, tmpx, tmpy;
        Node now;
        q.push({0, 0, -1, 1});
        vis[0][tmpx][tmpy] = true;
        while (q.size())
        {
            now = q.front();
            q.pop();
            // vis[(now.tmp > 0)][now.x][now.y] = 1;
            if (now.dis > n * n)
                break;
            if (now.x == n - 1 && now.y == n - 1)
            {
                ans = min(ans, now.dis);
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                tmpx = now.x + path[i], tmpy = now.y + path[i + 1];
                if (check(tmpx, tmpy))
                {
                    if (now.tmp == 1)
                    {
                        if (x[tmpx][tmpy] > x[now.x][now.y] && !vis[0][tmpx][tmpy])
                        {
                            q.push({tmpx, tmpy, -1, now.dis + 1});
                            vis[0][tmpx][tmpy] = true;
                        }
                    }
                    else if (x[tmpx][tmpy] < x[now.x][now.y] && !vis[1][tmpx][tmpy])
                    {
                        q.push({tmpx, tmpy, 1, now.dis + 1});
                        vis[1][tmpx][tmpy] = true;
                    }
                }
            }
        }

        MEM(vis, 0);
        qq.push({0, 0, 1, 1});
        vis[1][tmpx][tmpy] = true;
        while (qq.size())
        {
            now = qq.front();
            qq.pop();
            // vis[(now.tmp > 0)][now.x][now.y] = 1;
            if (now.dis > ans)
                break;
            if (now.dis > n * n)
                break;
            if (now.x == n - 1 && now.y == n - 1)
            {
                ans = min(ans, now.dis);
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                tmpx = now.x + path[i], tmpy = now.y + path[i + 1];
                if (check(tmpx, tmpy))
                {
                    if (now.tmp == 1)
                    {
                        if (x[tmpx][tmpy] > x[now.x][now.y] && !vis[0][tmpx][tmpy])
                        {
                            qq.push({tmpx, tmpy, -1, now.dis + 1});
                            vis[0][tmpx][tmpy] = true;
                        }
                    }
                    else if (x[tmpx][tmpy] < x[now.x][now.y] && !vis[1][tmpx][tmpy])
                    {
                        qq.push({tmpx, tmpy, 1, now.dis + 1});
                        vis[1][tmpx][tmpy] = true;
                    }
                }
            }
        }
        cout << (ans >= INF ? -1 : ans) << endl;
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
        END
    }
    return 0;
}