#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

int x[105][105];
int n, m;
int ans = INF;
void dfs(int i, int j, int sum)
{
    sum += x[i][j];
    if (j == m - 1)
    {
        ans = min(ans, sum);
        return;
    }
    else
    {
        for (int k = 0; k < n; k++)
        {
            if (k == i)
            {
                dfs(k, j + 1, sum);
            }
            else
            {
                dfs(k, j + 1, sum + 10);
            }
        }
    }
}

void sol()
{
    while (cin >> n >> m)
    {
        ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> x[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, 0);
        }
        cout << ans << endl;
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