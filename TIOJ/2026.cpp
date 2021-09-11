#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define lowbit(x) x &(-x)
int bit[1000006];

void update(int id, int val)
{
    while (id < 1000006)
    {
        bit[id] += val;
        id += lowbit(id);
    }
    return;
}
int query(int id)
{
    int sum = 0;
    while (id)
    {
        sum += bit[id];
        id -= lowbit(id);
    }
    return sum;
}

void sol()
{
    int t;
    while (cin >> t)
    {
        int cnt = 0;
        MEM(bit, 0);
        set<int> s;
        while (t--)
        {
            int a, b;
            cin >> a;
            if (a == 1)
            {
                cin >> b;
                update(b, 1);
                s.insert(b);
            }
            else
            {
                int l = 1, r = 1000006;
                int m = (l + r) >> 1;
                int owo = s.size() / 2 + 1;
                int ans = m;
                while (l <= r)
                {
                    m = (l + r) >> 1;
                    int qq = query(m);
                    if (qq < owo)
                        l = m + 1;
                    else if (qq > owo)
                        r = m - 1;
                    else
                    {
                        ans = min(ans, m);
                        r = m - 1;
                    }
                }
                cout << l << endl;
            }
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