#pragma region 模板
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
#pragma endregion
/******************************************************************************/

void sol()
{
    int k, n;
    int x[100005];
    while (cin >> k >> n)
    {
        int ans = 0;
        fr(i, 0, n)
        {
            cin >> x[i];
        }
        fr(i, 0, n - 1)
        {
            //int a = x[i] * (int)pow(k % 2, n - i - 1);
            ans += (x[i] % 2 & k % 2);
            //DB(ans);
        }
        ans += x[n - 1] % 2;
        //cout << ans << endl;
        if (ans % 2 == 0)
        {
            cout << "even" << endl;
        }
        else
            cout << "odd" << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
        sol();
    return 0;
}