#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
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

int st[200005][20];

void sol()
{
    int n;
    cin >> n;
    int x[n], ans = 0;
    int tmp = 0;
    cin >> x[0];
    for (int i = 1; i < n; i++)
    {
        cin >> x[i];
        st[i - 1][0] = abs(x[i] - x[i - 1]);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    n--;
    int maxj = 0;
    for (int j = 1; j < 20; j++)
    {
        if ((1 << j) > n)
            break;
        for (int i = 0; i < n; i++)
        {
            int a = 1 << (j - 1);
            if (i + a * 2 > n)
                break;
            st[i][j] = __gcd(st[i][j - 1], st[i + a][j - 1]);
            if (st[i][j])
                maxj = j;
            //cout << st[i][j] << " ";
        }
    }
    int cnt = 0, mx = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l = i;
        if (n - l + 1 < mx)
            break;
        for (int j = i + mx; j < n; j++)
        {
            r = j;
            int range = r - l + 1;
            int lg = log2(range);
            if (__gcd(st[i][lg], st[j - (1 << lg) + 1][lg]) != 1)
            {
                mx = max(mx, range);
            }
            else
            {
                break;
            }
        }
    }
    cout << mx + 1 << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
            END
        }
    return 0;
}