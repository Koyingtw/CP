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
    pr x[n];
    int a = 0, b = 0;
    int cnt1[n + 1], cnt2[n + 1];
    vector<int> v[n];
    MEM(cnt1, 0);
    MEM(cnt2, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].F >> x[i].S;
        x[i].F--, x[i].S--;
        cnt1[x[i].F]++;
        cnt2[x[i].S]++;
    }
    int ans = (n * (n - 1) * (n - 2)) / 6;
    //cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        ans -= (cnt1[x[i].F] - 1) * (cnt2[x[i].S] - 1);
    }
    cout << ans << endl;
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