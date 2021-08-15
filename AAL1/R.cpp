#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ull unsigned long long
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
    int a, d, n;
    while (cin >> a >> d >> n)
    {
        // for (int i = 1; i < a + d * (n - 1); i++)
        // {
        //     cout << i << ": " << __builtin_popcount(i) << endl;
        // }

        ull ans = 0;
        if (n % 2)
        {
            for (int i = 0; i < n; i++)
                ans += (a + a + d * (n - 1)) / 2;
            //ans =  * n;
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                ans = (a + a + d * (n - 1));
            }
        }
        int mx = a + d * (n - 1);
        int tmp = 2, now = 1;
        while (tmp <= mx)
        {
            if (tmp < a)
            {
                for (int i = 0; i < now; i++)
                {
                    ans += n;
                }
                tmp <<= 1;
                now++;

                continue;
            }
            else
            {
                int cnt = (tmp - a) / d + ((tmp - a) % d != 0) + 1;
                for (int i = 0; i < now; i++)
                {
                    ans += (n - cnt + 1);
                }
                tmp <<= 1;
                now++;
            }
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