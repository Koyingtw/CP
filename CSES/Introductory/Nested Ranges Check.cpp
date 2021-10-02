#pragma region
#include <bits/stdc++.h>
#include <bits/extc++.h>
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
#define lowbit(x) x &(-x)
#define MAXN 400005
#if ONLINE_JUDGE
#define END return 0;
#else
#define END \
    system("pause");
#endif
struct BIT
{
    int bit[MAXN];
    void update(int id, int val)
    {
        while (id < MAXN)
        {
            bit[id] += val;
            id += lowbit(id);
        }
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
} BIT;
struct in
{
    int l, r, id;
} x[200005];

bool cmp(in a, in b)
{
    if (a.l != b.l)
        return a.l < b.l;
    else
        return a.r > b.r;
}

void sol()
{
    int n;
    cin >> n;
    set<int> s;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].l >> x[i].r;
        x[i].id = i;
        //s.insert(x[i].l);
        s.insert(x[i].r);
    }
    int cnt = 1;
    for (int it : s)
    {
        m[it] = cnt;
        cnt++;
    }

    int ans1[n], ans2[n];
    sort(x, x + n, cmp);
    for (int i = 0; i < n; i++)
    {
        ans2[x[i].id] = i - BIT.query(m[x[i].r] - 1);
        BIT.update(m[x[i].r], 1);
    }
    for (int i = 0; i < n; i++)
    {
        BIT.update(m[x[i].r], -1);
        ans1[x[i].id] = BIT.query(m[x[i].r]);
    }
    for (int i = 0; i < n; i++)
        cout << (ans1[i] > 0) << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << (ans2[i] > 0) << " ";
    cout << endl;
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
    END
}