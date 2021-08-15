#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
#define ll long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define END cout.flush();
#define lowbit(x) x &(-x);
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
int n = 10;

int BIT[MAXN];
int query(int i)
{
    int sum = 0;
    while (i)
    {
        sum += BIT[i];
        i -= lowbit(i);
    }
    return sum;
}

void update(int i, int val)
{
    while (i < MAXN)
    {
        BIT[i] += val;
        i += lowbit(i);
    }
    return;
}

void sol()
{
    while (cin >> n)
    {
        int x[n + 1];
        ll ans = 0;
        set<int> s;
        map<int, int> m;
        MEM(BIT, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            s.insert(x[i]);
        }
        int cnt = 1;
        for (int i : s)
        {
            m[i] = cnt;
            cnt++;
        }
        for (int i = 1; i <= n; i++)
        {
            update(m[x[i]], 1);
            ans += i - query(m[x[i]]);
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