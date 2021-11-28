#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
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

vector<int> v[200005], deps[200005];
int dep[200005], l[200005], r[200005];
bitset<200005> vis;
int cnt = 0;
void dfs(int i, int depth)
{
    vis[i] = 1;
    l[i] = cnt++;
    deps[depth].push_back(i);
    dep[i] = depth;
    for (int e : v[i])
    {
        if (!vis[e])
        {
            dfs(e, depth + 1);
        }
    }
    r[i] = cnt;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        for (int i = 2, a; i <= n; i++)
        {
            cin >> a;
            v[i].push_back(a);
            v[a].push_back(i);
        }
        dfs(1, 0);
        int q, a, b, ans = 0;
        cin >> q;
        while (q--)
        {
            cin >> a >> b;
            ans = 0;
            if (dep[a] >= b || deps[b].size() == 0)
            {
                cout << (dep[a] == b) << endl;
                continue;
            }
            cout << lower_bound() << endl;
        }
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