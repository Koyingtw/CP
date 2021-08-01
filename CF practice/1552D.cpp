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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

bool cmp(int a, int b)
{
    return abs(a) > abs(b);
}
int N;
bool dfs(int x[], int i, int sum, int n)
{
    if (sum == x[n])
        return 1;
    if (i == N - 1)
        return 0;
    bool b = 0;
    if (i + 1 != n)
    {
        if (dfs(x, i + 1, sum - x[i + 1], n) || dfs(x, i + 1, sum, n) || dfs(x, i + 1, sum + x[i + 1], n))
            b = 1;
    }
    else if (i != N - 2)
    {
        if (dfs(x, i + 2, sum + x[i + 2], n) || dfs(x, i + 2, sum - x[i + 2], n) || dfs(x, i + 2, sum, n))
            b = 1;
    }
    return b;
}

void sol()
{
    int n;
    cin >> n;
    N = n;
    int x[n];
    fr(i, 0, n)
    {
        cin >> x[i];
    }
    //sort(x, x + n, cmp);
    bool yes = 0;
    if (n > 1)
    {
        if (dfs(x, 1, 0, 0) || dfs(x, 1, x[1], 0) || dfs(x, 1, -x[1], 0))
        {
            yes = 1;
        }
    }
    if (n == 1)
        yes = (x[0] == 0);
    fr(i, 1, n)
    {
        if (i)
        {
            if (dfs(x, 0, x[0], i) || dfs(x, 0, -x[0], i) || dfs(x, 0, 0, i))
            {
                yes = 1;
                break;
            }
        }
    }

    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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