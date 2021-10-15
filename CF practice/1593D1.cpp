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
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int mn = *min_element(x, x + n);
    int mx = *max_element(x, x + n);
    //sort(x, x + n);
    // for (int i = 0; i < n; i++)
    //     cout << x[i] << " ";
    // cout << endl;

    if (mx - mn == 0)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 1;
    for (int i = mx - mn; i > 0; i--)
    {
        bool yes = 1;
        for (int j = 0; j < n; j++)
        {
            if ((x[j] - mn) % i != 0)
                yes = 0;
        }
        if (yes)
        {
            cout << i << endl;
            break;
        }
    }
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