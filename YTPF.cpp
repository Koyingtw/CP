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
#if ONLINE_JUDGE
#define endl "\n"
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define lowbit(x) x &(-x)
#define MAXN 200005
struct bit
{
    int arr[MAXN];
    int query(int i)
    {
        if (i == 0)
            return 0;
        int sum = 0;
        while (i)
        {
            sum += arr[i];
            i -= lowbit(i);
        }
        return sum;
    }

    void update(int i, int val)
    {
        while (i < MAXN)
        {
            arr[i] += val;
            i += lowbit(i);
        }
        return;
    }
} b1, b2;

bool cmp(pr a, pr b) { return a.S < b.S; }

void sol()
{
    int n;
    while (cin >> n)
    {
        MEM(b1.arr, 0);
        MEM(b2.arr, 0);
        pr x[n];
        int ans1[n], ans2[n], ans = 0;
        set<int> s;

        for (int i = 0; i < n; i++)
        {
            cin >> x[i].F;
            x[i].S = i;
            s.insert(x[i].F);
        }
        map<int, int> m;
        int cnt = 1;
        for (int i : s)
        {
            m[i] = cnt;
            cnt++;
        }
        // for (int i = 0; i < n; i++)
        //     cout << m[x[i].F] << " ";
        // cout << endl;

        for (int i = 0; i < n; i++)
        {
            if (x[i].F & 1)
            {
                ans1[i] = b1.query(m[x[i].F] - 1);
                ans2[i] = b2.query(m[x[i].F] - 1);
                b1.update(m[x[i].F], 1);
            }
            else
            {
                ans1[i] = b1.query(m[x[i].F] - 1);
                ans2[i] = b2.query(m[x[i].F] - 1);
                b2.update(m[x[i].F], 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (x[i].F & 1)
            {
                ans += (b1.query(m[x[i].F] - 1) - ans1[i]) * ans2[i];
                ans += (b2.query(m[x[i].F] - 1) - ans2[i]) * ans1[i];
            }
            else
            {
                ans += (b2.query(m[x[i].F] - 1) - ans2[i]) * ans2[i];
                ans += (b1.query(m[x[i].F] - 1) - ans1[i]) * ans1[i];
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