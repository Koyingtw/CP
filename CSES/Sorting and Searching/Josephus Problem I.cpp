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
int a[200005];

int g(int n, int k)
{
    if (n == 1)
        return 1;
    else
    {
        int a = (g(n - 1, k) + k) % n;
        cout << a << endl;
        return a;
    }
}
void sol()
{
    int n, k = 2;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int now = k;
        cout << g(n, k) << endl;
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
    }
    return 0;
}