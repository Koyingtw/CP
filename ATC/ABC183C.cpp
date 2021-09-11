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

void sol()
{
    int n, k;
    while (cin >> n >> k)
    {
        int x[n][n], ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> x[i][j];
            }
        }
        vector<int> v;
        for (int i = 1; i < n; i++)
            v.push_back(i);
        do
        {
            int tmp = 0;
            int sum = 0;
            for (int i : v)
            {
                sum += x[tmp][i];
                tmp = i;
            }
            sum += x[tmp][0];
            if (sum == k)
                ans++;

        } while (next_permutation(v.begin(), v.end()));
        cout << ans << endl;
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
        END
    }
    return 0;
}
