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
const int INF = 0x3f3f3f3f;
using namespace std;
/******************************************************************************/
int x[3] = {1, -1, 0};
int y[3] = {1, -1, 0};
void sol()
{
    int n, m;
    cin >> n >> m;
    bool b[n + 2][m + 2];
    fr(i, 0, n + 1)
    {
        fr(j, 0, m + 1)
        {
            b[i][j] = 1;
        }
    }
    fr(i, 1, n + 1)
    {
        fr(j, 1, m + 1)
        {
            if (i != 1 && i != n && j != 1 && j != m)
            {
                b[i][j] = 0;
            }
            if (b[i][j] == 1)
            {
                fr(k, 0, 3)
                {
                    fr(l, 0, 3)
                    {
                        if (k * l != 4)
                        {
                            b[i + x[k]][j + y[l]] = 0;
                        }
                    }
                }
            }
        }
    }
    fr(i, 1, n + 1)
    {
        fr(j, 1, m + 1)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
            sol();
    return 0;
}