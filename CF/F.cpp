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
const int INF = 0x3f3f3f3f;
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

void sol()
{
    int n;
    cin >> n;
    int x[n];
    fr(i, 0, n) cin >> x[i];
    int g = x[0];
    int tmp = g;
    int cnt = 0;
    fr(i, 1, n)
    {
        tmp = __gcd(g, x[i]);
        if (tmp != g)
        {
            cnt = i;
        }
        g = tmp;
        x[i - 1] = tmp;
    }
    tmp = 0;
    int mx = 0;
    fr(i, 0, n)
    {
        if (x[i] == x[(i + 1) % n])
            tmp++;
        else
        {
            mx = max(mx, tmp);
            tmp = 0;
        }
    }
    cout << cnt + mx << endl;
}

signed main()
{
    Koying int t = 1;
    while (cin >> t)
        while (t--)
            sol();
    return 0;
}