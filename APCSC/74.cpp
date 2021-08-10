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
    int n, k, p;
    while (cin >> n >> k >> p)
    {
        int x[p], ans = 0;
        priority_queue<pr> pq;
        set<pr> s{{0, 0}};
        map<int, int> m;
        for (int i = 0; i < p; i++)
        {
            cin >> x[i];
            m[x[i]]++;
        }
        for (int i = 0; i < k; i++)
        {
            if (s.count({m[x[i]], x[i]}) == 0)
            {
                s.insert({--m[x[i]], x[i]});
                ans++;
            }
            else
            {
                s.erase({m[x[i]], x[i]});
                s.insert({--m[x[i]], x[i]});
            }
        }
        for (int i = k; i < p; i++)
        {
            if (s.size() == k + 1 && s.count({m[x[i]], x[i]}) == 0)
            {
                s.erase(++s.begin());
                s.insert({--m[x[i]], x[i]});
                ans++;
            }
            else
            {
                s.erase({m[x[i]], x[i]});
                s.insert({--m[x[i]], x[i]});
            }
        }
        cout << ans << endl;
    }
}
// 紀錄區間中每個元素的剩餘數量
// 如果要消除，優先消除剩餘數量最少的
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