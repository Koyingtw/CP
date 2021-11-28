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
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
int x[100005];
void dfs(int i)
{
    if (i == 1)
    {
        cout << 1;
        return;
    }
    dfs(x[i]);
    cout << "->" << i;
}

void sol()
{
    int n, q;
    while (cin >> n)
    {
        for (int i = 2; i <= n; i++)
            cin >> x[i];
        cin >> q;
        int a;
        while (q--)
        {
            cin >> a;
            dfs(a);
            cout << endl;
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
    }
    return 0;
}