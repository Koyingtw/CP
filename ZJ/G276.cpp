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
int n, m, k;

bool check(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void sol()
{
    while (cin >> n >> m >> k)
    {
        int x[n][m], y[k][4];
        bool alive[k];
        bool dead[k];
        int cnt = k, sum = 0;
        for (int i = 0; i < n; i++)
            MEM(x[i], 0);
        for (int i = 0; i < k; i++)
        {
            alive[i] = 1;
            dead[i] = 0;
            for (int j = 0; j < 4; j++)
                cin >> y[i][j];
        }
        while (cnt > 0)
        {
            for (int i = 0; i < k; i++)
            {
                if (alive[i] == 0)
                    continue;
                x[y[i][0]][y[i][1]] = 1;
            }
            for (int i = 0; i < k; i++)
            {
                if (alive[i] == 0)
                    continue;
                y[i][0] += y[i][2];
                y[i][1] += y[i][3];
                if (check(y[i][0], y[i][1]) == 0)
                {
                    alive[i] = 0;
                    cnt--;
                    continue;
                }
                if (x[y[i][0]][y[i][1]])
                {
                    cnt--;
                    dead[i] = 1;
                }
            }
            for (int i = 0; i < k; i++)
            {
                if (alive[i] == 0)
                    continue;
                if (dead[i])
                {
                    x[y[i][0]][y[i][1]] = 0;
                    alive[i] = 0;
                }
            }
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (x[i][j] > 0)
                    sum++;
            }
        }
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