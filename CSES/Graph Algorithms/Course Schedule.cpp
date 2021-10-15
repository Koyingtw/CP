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
    while (cin >> n >> m)
    {
        vector<int> v[n + 1];
        int deg[n + 1] = {0};
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            deg[b]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                q.push(i);
        vector<int> ans;
        while (q.size())
        {
            int now = q.front();
            q.pop();
            ans.push_back(now);

            for (int e : v[now])
            {
                deg[e]--;
                if (deg[e] == 0)
                    q.push(e);
            }
        }
        if (ans.size() != n)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
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