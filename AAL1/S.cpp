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

int f(int n) { return (1 + n) * n / 2; }

void sol()
{
    int n, m;
    while (cin >> n)
    {
        int x[n], cnt[n], out[n];
        int alive = n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            out[i] = -1;
            cnt[i] = 0;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int in;
            cin >> in;
            x[in - 1] -= (i + 1) * (alive - 1);
            cnt[in - 1] += (i + 1);
            if (x[in - 1] + f(i + 1) - cnt[in - 1] < 0)
            {
                alive--;
                out[in - 1] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (out[i] == -1)
                cout << x[i] + f(m) - cnt[i] << " ";
            else
            {
                if (out[i] == 0)
                    cout << x[i] << " ";
                else
                    cout << x[i] + f(out[i] + 1) - cnt[i] << " ";
            }
        }
        cout << endl;
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