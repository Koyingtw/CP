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
    int n, m;
    while (cin >> n >> m)
    {
        int x[n];
        fr(i, 0, n)
        {
            cin >> x[i];
        }
        sort(x, x + n, cmp);
        int ans = 0;
        fr(i, 0, n)
        {
            if (m <= 0)
                break;
            ans++;
            m -= x[i];
        }
        cout << ans << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}