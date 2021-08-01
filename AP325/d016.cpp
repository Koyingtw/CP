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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int m, n;
    while (cin >> m >> n)
    {
        int ans = 0;
        string s[n];
        int x[n];
        fr(i, 0, n)
        {
            cin >> s[i];
            x[i] = 0;
            bool b[m + 1];
            MEM(b, 0);
            fr(j, 0, s[i].size())
            {
                b[s[i][j] - 'A' + 1] = 1;
            }
            fr(j, 1, m + 1)
            {
                if (b[j])
                    x[i] += 1 << j;
            }
        }
        int a = (1 << (m + 1)) - 2;
        sort(x, x + n);
        set<int> st;
        fr(i, 0, n - 1)
        {
            ans += binary_search(x + i + 1, x + n, x[i] ^ a);
        }

        DB(ans);
    }
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
        sol();
    return 0;
}