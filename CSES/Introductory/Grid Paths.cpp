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

string s;
int path[5] = {1, 0, -1, 0, 1}; //R D L U
string ps = "RDLU";
bool yes = 0;
int sum = 0;
bool vis[7][7];
bool check(int x, int y)
{
    return (x < 7 && x >= 0 && y < 7 && y >= 0);
}

void dfs(int x, int y, int dep, string ans)
{
    if (vis[x][y])
        return;
    //cout << ans << endl;
    if (x == 0 && y == 0 && dep == 48)
    {
        sum++;
        //cout << ans << endl;
        //yes = 1;
        return;
    }
    if (x < 0 || y < 0 || x >= 7 || y >= 7 || dep >= 48)
        return;
    vis[x][y] = 1;

    if (s[dep] == 'L')
    {
        if (check(x - 1, y) == 0 && !vis[x - 1][y - 1] && !vis[x + 1][y - 1])
        {
        	return;
        }
        dfs(x - 1, y, dep + 1, ans + 'L');
    }
    else if (s[dep] == 'R')
    {
        dfs(x + 1, y, dep + 1, ans + 'R');
    }
    else if (s[dep] == 'U')
    {
        dfs(x, y + 1, dep + 1, ans + 'U');
    }
    else if (s[dep] == 'D')
    {
        dfs(x, y - 1, dep + 1, ans + 'D');
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            dfs(x + path[i], y + path[i + 1], dep + 1, ans + ps[i]);
        }
    }
    vis[x][y] = 0;
    return;
}
void sol()
{
    while (cin >> s)
    {
        string ans;
        MEM(vis, 0);
        dfs(0, 6, 0, ans);
        cout << sum << endl;
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