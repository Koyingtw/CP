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
bool same(int x, int y) // 比較是否相同
{
    return dsu[x] == dsu[y];
}
void unite(int x, int y) //合併
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (x < y)
        swap(x, y);
    dsu[y] = x;
    cnt[x] += cnt[y];
    return;
}
void sol()
{
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        pr x[k];
        init(k);
        int ans = k;
        for (int i = 0; i < k; i++)
        {
            cin >> x[i].F >> x[i].S;
        }
        sort(x, x + k);
        for (int i = 1; i < k; i++)
        {
            set<int> tmp;
            for (int j = i - 1; j >= 0; j--)
            {
                if (x[i].F - x[j].F >= 3)
                    break;
                if (abs(x[i].S - x[j].S) < 3)
                {
                    ans -= (find(j) != i);
                    unite(i, j);
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
        END
    }
    return 0;
}