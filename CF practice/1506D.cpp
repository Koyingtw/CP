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
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n);
    int mxcnt = 1, cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (x[i] == x[i - 1])
            cnt++;
        else
        {
            mxcnt = max(mxcnt, cnt);
            cnt = 1;
        }
    }
    mxcnt = max(mxcnt, cnt);
    int ans = mxcnt - (n - mxcnt);
    cout << (ans <= 0 ? n % 2 : ans) << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}