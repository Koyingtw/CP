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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

const int MAXN = 2e5 + 5;
int dsu[MAXN]; //dsu
int cnt[MAXN]; //set size

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
    if (x > y)
        swap(x, y);
    dsu[y] = x;
    return;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        pr x[n];
        init(n + 1);
        for (int i = 0; i < n; i++)
            cin >> x[i].F >> x[i].S;
        sort(x, x + n);
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (x[j].S <= x[i].F)
                    break;
                if (x[i].F > x[j].F && x[i].F < x[j].S)
                {
                    unite(i, j);
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                if (x[j].F >= x[i].S)
                    break;
                if (x[i].F > x[j].F && x[i].F < x[j].S)
                {
                    unite(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dsu[i] == i)
                ans++;
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