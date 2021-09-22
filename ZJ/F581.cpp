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
    int n, q;
    while (cin >> n >> q)
    {
        int x[n];
        int pre[n + 1] = {0};

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            pre[i + 1] = pre[i] + x[i];
        }
        int tmp = 0;
        int find;
        while (q--)
        {
            int k;
            cin >> k;
            find = lower_bound(pre, pre + n + 1, (k + pre[tmp]) % pre[n]) - pre;
            tmp = find;
        }
        cout << (tmp) % n << endl;
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