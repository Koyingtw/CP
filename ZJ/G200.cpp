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
    string root;
    int n, q;
    while (cin >> root >> n >> q)
    {
        map<string, int> m;
        vector<string> v[10005];
        v[1].push_back(root);
        m[root] = 1;
        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            m[b] = m[a] + 1;
            v[m[b]].push_back(b);
        }
        for (int i = 0; i < q; i++)
        {
            int a;
            cin >> a;
            for (string it : v[a])
                cout << it << " ";
            cout << endl;
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
    }
    return 0;
}