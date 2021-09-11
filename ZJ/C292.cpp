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

int px[4] = {0, -1, 0, 1};
int py[4] = {-1, 0, 1, 0};

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> x[i][j];
        int a = n / 2, b = n / 2;
        vector<int> ans;
        cout << x[a][b];
        for (int step = 1; step < n; step++)
        {
            for (int k = 0; k < 2; k++)
                for (int i = 0; i < step; i++)
                {
                    a += px[(((step + 1) % 2) * 2 + m + k) % 4];
                    b += py[(((step + 1) % 2) * 2 + m + k) % 4];
                    cout << x[a][b];
                }
        }
        int step = n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            a += px[(((step + 1) % 2) * 2 + 2 + m) % 4];
            b += py[(((step + 1) % 2) * 2 + 2 + m) % 4];
            cout << x[a][b];
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
        END
    }
    return 0;
}