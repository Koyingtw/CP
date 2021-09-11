#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
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
    int n;
    while (cin >> n)
    {
        vector<int> v;
        int ans = 0;
        while (n--)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                int b;
                cin >> b;
                v.push_back(b);
                sort(v.begin(), v.end());
            }
            else
            {
                if (v.size())
                {
                    ans += v[v.size() - 1];
                    v.pop_back();
                }
            }
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
    }
    return 0;
}