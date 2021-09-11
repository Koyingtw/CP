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
    int n, k;
    while (cin >> n >> k)
    {
        int x[n];
        int ans = -INF;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            if (i)
                x[i] += x[i - 1];
            if (x[i] <= k)
                ans = max(ans, x[i]);
        }
        set<int> s{0};
        for (int i = 0; i < n; i++)
        {
            auto find = s.lower_bound(x[i] - k); //x[i] - x[j] == k  x[j] = x[i] - k
            if (x[i] - *find <= k)
                ans = max(ans, x[i] - *find);
            if (find != s.begin())
                find--;
            if (x[i] - *find <= k)
                ans = max(ans, x[i] - *find);
            s.insert(x[i]);
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