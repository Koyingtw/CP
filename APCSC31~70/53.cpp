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
    int n, m;
    while (cin >> n >> m)
    {
        int x[n];
        map<int, int> mp;
        vector<int> v[m + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < m; i++)
        {
            int a;
            cin >> a;
            mp[a] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[x[i]])
            {
                v[mp[x[i]]].push_back(i + 1);
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (v[i].size())
            {
                cout << v[i][0] << " " << v[i].size() << endl;
            }
            else
                cout << -1 << " 0" << endl;
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