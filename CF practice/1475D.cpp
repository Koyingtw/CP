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
    int n, m;
    cin >> n >> m;
    int tmp = 0;
    pr x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].F;
        tmp += x[i].F;
    }
    for (int i = 0; i < n; i++)
        cin >> x[i].S;
    if (tmp < m)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        if (x[i].S == 1)
            v1.push_back(x[i].F);
        else
            v2.push_back(x[i].F);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());

    for (int i = 1; i < v1.size(); i++)
        v1[i] = v1[i - 1] + v1[i];
    for (int i = 1; i < v2.size(); i++)
        v2[i] = v2[i - 1] + v2[i];

    int cnt = 0, ans = INF;
    if (v2.size() && v2[v2.size() - 1] >= m)
        ans = 2 * (lower_bound(v2.begin(), v2.end(), m) - v2.begin() + 1);
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] >= m)
            ans = min(ans, i + 1);
        if (v2.size() && v2[v2.size() - 1] >= m - v1[i])
            ans = min(ans, i + 1 + 2 * (lower_bound(v2.begin(), v2.end(), m - v1[i]) - v2.begin() + 1));
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