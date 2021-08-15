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
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        int cnt[n];
        //MEM(ans, 0);
        MEM(cnt, 0);
        for (int i = 0; i < k; i++)
        {
            int a;
            cin >> a;
            cnt[a - 1]++;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ((m - k + cnt[i] > 0) ? "Yes" : "No") << endl;
        }
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