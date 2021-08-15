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
void sol()
{
    int n;
    while (cin >> n)
    {
        int x[n], ans = INF, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            sum += x[i];
        }
        for (int i = 1; i < (1 << n); i++)
        {
            int cnt = 0, a = i, tmp = 0;
            while (a)
            {
                if (a % 2 == 1)
                {
                    tmp += x[cnt];
                }
                cnt++;
                a >>= 1;
            }
            ans = min(ans, abs(tmp - (sum - tmp)));
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
        END
    }
    return 0;
}