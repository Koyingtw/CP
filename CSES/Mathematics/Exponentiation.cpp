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

#define P 1000000007

int f(int n, int m)
{
    if (m == 0)
        return 1;
    if (m == 1)
        return n;
    if (m & 1)
        return (n * f(n, m - 1)) % P;
    int owo = f(n, m / 2);
    return (owo * owo) % P;
}

void sol()
{
    int n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << 1 << endl;
        return;
    }
    stack<int> s;
    while (m)
    {
        s.push(m % 2);
        m >>= 1;
    }
    int ans = n % P;
    s.pop();
    while (s.size())
    {
        ans *= ans;
        ans %= P;
        if (s.top())
        {
            ans *= n;
        }
        s.pop();
        ans %= P;
    }
    cout << ans << endl;
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