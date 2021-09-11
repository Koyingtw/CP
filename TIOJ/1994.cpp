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
bool vis[1 << 11][1 << 11];
int path[1 << 11][1 << 11];
int px[4] = {0, 0, 1, -1};
int py[4] = {1, -1, 0, 0};
int cube = 0;

bool check(int x, int y)
{
    return (x >= 0 && x < cube && y >= 0 && y < cube && vis[x][y] == 0);
}

void dfs(int i, int j, int cnt)
{
    vis[i][j] = 1;
    path[i][j] = cnt;
    if (i == cube - 1 && j == cube - 1)
        return;
    for (int k = 0; k < 4; k++)
    {
        if (check(i + px[k], j + py[k]))
        {
            dfs(i + px[k], j + py[k], cnt + 1);
        }
    }
    vis[i][j] = 0;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        cube = 1 << n;
        for (int i = 0; i < cube; i++)
        {
            MEM(path[i], 0);
            MEM(vis[i], 0);
        }
        dfs(0, 0, 0);

        for (int i = 0; i < cube; i++)
        {
            for (int j = 0; j < cube; j++)
            {
                cout << path[i][j] << " ";
            }
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