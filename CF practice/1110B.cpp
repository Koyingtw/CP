#pragma region
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
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        int x[n];
        vector<int> v;
        fr(i, 0, n)
        {
            cin >> x[i];
            if (i)
                v.push_back(x[i] - x[i - 1]);
        }
        int ans = x[n - 1] - x[0] + 1;
        //cout << ans << endl;
        sort(v.begin(), v.end(), greater<int>());
        fr(i, 0, k - 1)
        {
            ans -= v[i] - 1;
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
        sol();
    return 0;
}