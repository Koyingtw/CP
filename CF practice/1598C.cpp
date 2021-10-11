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
    int x[n], sum = 0, ans = 0;
    double k = 0.0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }
    if ((sum * 2) % n != 0)
    {
        cout << 0 << endl;
        return;
    }
    int find = ((sum * 2) / n);
    k = (double)(sum / n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        ans += m[find - x[i]];
        m[x[i]]++;
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