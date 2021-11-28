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
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;

using namespace std;
#pragma endregion
/******************************************************************************/

const int MAXN = 1e5 + 5;
int dsu[MAXN]; // dsu
int cnt[MAXN]; // set size

void init(int n) //初始化
{
    for (int i = 0; i < n; i++)
    {
        dsu[i] = i;
        cnt[i] = 1;
    }
}

int find(int i) //查找
{
    if (dsu[i] == i)
        return i;
    else
        return dsu[i] = find(dsu[i]);
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y) //合併
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (cnt[x] < cnt[y])
        swap(x, y);
    dsu[y] = x;
    cnt[x] += cnt[y];
    return;
}

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> ans;
        pr in[m];
        int sum = n * (n - 1) / 2;
        init(n);
        for (int i = 0; i < m; i++)
        {
            cin >> in[i].F >> in[i].S;
        }
        for (int i = m - 1; i >= 0; i--)
        {
            ans.push_back(sum);
            if (same(in[i].F, in[i].S))
                continue;
            sum -= cnt[find(in[i].F)] * cnt[find(in[i].S)];
            unite(in[i].F, in[i].S);
        }
        for (int i = m - 1; i >= 0; i--)
            cout << ans[i] << endl;
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