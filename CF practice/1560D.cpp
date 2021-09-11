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
string x[63];
void pre()
{
    int cnt = 1;
    for (int i = 0; i < 63; i++)
    {
        x[i] = to_string(cnt);
        cnt <<= 1;
    }
}

void sol()
{
    cin.ignore();
    string s;
    cin >> s;
    int ans = INF;
    for (int k = 0; k < 63; k++)
    {
        int n = s.size();
        int m = x[k].size();
        int now = 0;
        int cnt = 0;
        for (int i = 0; i < m && now < n; i++)
        {
            for (int j = now; now < n; j++)
            {
                now = j;
                if (s[j] == x[k][i])
                {
                    cnt++;
                    now = j + 1;
                    break;
                }
            }
        }
        ans = min(ans, m - cnt + n - cnt);
        if (ans == 0)
            break;
    }
    cout << ans << endl;
}

signed main()
{
    Koying;
    int t = 1;
    pre();
    while (cin >> t)
    {

        while (t--)
        {
            sol();
            END
        }
    }
    return 0;
}