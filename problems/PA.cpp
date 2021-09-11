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

void sol()
{
    int n, k;
    while (cin >> n >> k)
    {
        int a, b;
        cin >> a >> b;
        int ans = n;
        pr tmp = {0, 0};
        for (int i = 0; i <= 10; i++)
        {
            for (int j = 0; j <= 10; j++)
            {
                if (n - a * j - b * i >= k && n - a * j - b * i < ans)
                {
                    tmp = {j, i};
                    ans = n - a * j - b * i;
                }
                if (n - a * j - b * i >= k && n - a * j - b * i == ans && tmp.first < j)
                {
                    tmp = {j, i};
                    ans = n - a * j - b * i;
                }
            }
        }
        cout << tmp.first << " " << tmp.second << " " << ans - k << endl;
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