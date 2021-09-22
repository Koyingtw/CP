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
vector<int> v[100005];
void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        ans = 0;
        MEM(vis, 0);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        queue<pr> q;
        q.push(1, 0);
        while (q.size())
        {
            for (int e :)
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