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
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
int n, m, k;
vector<int> v[200005];
int in[200005];
void sol()
{
    while (cin >> n >> m >> k)
    {
        MEM(in, 0);
        for (int i = 0, a, b; i < m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            in[b]++, in[a]++;
        }
        queue<int> q;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] < k)
            {
                q.push(i);
                in[i] = INF;
            }
        }
        ans += q.size();
        while (q.size())
        {
            int now = q.front();
            q.pop();
            for (int e : v[now])
            {
                in[e]--;
                if (in[e] < k)
                {
                    ans++;
                    q.push(e);
                    in[e] = INF;
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
    // while (cin >> t)
    while (t--)
    {
        sol();
    }
    return 0;
}