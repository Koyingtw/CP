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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void f(int n)
{
    int cnt = 1;
    int tmp = 9;
    int sum = 0;
    while (n > cnt * tmp)
    {
        n -= cnt * tmp;
        sum += tmp;
        cnt++;
        tmp *= 10;
    }
    string ans = to_string(sum + (n + cnt - 1) / cnt);
    //cout << ans << endl;
    cout << ans[((n - 1) % cnt)] << endl;
}

void sol()
{
    int n;
    cin >> n;
    f(n);
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}