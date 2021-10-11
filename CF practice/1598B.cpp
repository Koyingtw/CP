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

void sol()
{
    int n;
    cin >> n;
    int x[n][5];
    int cnt[5] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> x[i][j];
            cnt[j] += x[i][j];
        }
    }
    bool ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (ans)
            break;
        for (int j = i + 1; j < 5; j++)
        {
            bool can = 1;
            // if (cnt[i] + cnt[j] < n)
            //     continue;
            int a, b, c;
            a = b = c = 0;
            for (int k = 0; k < n; k++)
            {
                if (x[k][i] & x[k][j])
                    c++;
                else if (x[k][i])
                    a++;
                else if (x[k][j])
                    b++;
                else
                    can = 0;
            }
            // cout << i << " " << j << " " << a << " " << b << " " << c << endl;
            // cout << a + c << " " << a + c << endl;
            if (can && a <= n / 2 && b <= n / 2 && a + c >= n / 2 && b + c >= n / 2)
                ans = 1;
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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