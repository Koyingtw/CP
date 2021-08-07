#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define int long long
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

int n, k;
void dfs(int x[], vector<int> v, int i)
{
    v.emplace_back(x[i]);
    if (v.size() == k)
    {
        for (int j : v)
            cout << j << " ";
        cout << endl;
        return;
    }
    if (i == n - 1)
        return;
    for (int j = i + 1; j < n; j++)
        dfs(x, v, j);
}

void sol()
{
    cin >> n >> k;
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n);
    vector<int> v;
    for (int i = 0; i < n - k + 1; i++)
        dfs(x, v, i);
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