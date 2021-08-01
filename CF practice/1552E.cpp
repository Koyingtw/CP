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
#if ONLINE_JUDGE
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, k;
    while (cin >> n >> k)
    {
        int x[n * k], mx = (n / (k - 1)) + ((n % (k - 1)) != 0);

        vector<int> v[n + 1];
        pr ans[n + 1];
        fr(i, 0, n + 1)
        {
            ans[i] = {-1, -1};
        }
        int tmp = -1, last = -1;
        int cnt = 0;
        fr(i, 0, n * k)
        {
            cin >> x[i];
            v[x[i]].push_back(i);
            int a = v[x[i]].size();
            if (a > 1 && v[x[i]][a - 2] > tmp)
            {
                if (ans[x[i]].F != -1 && ans[x[i]].S != -1)
                    continue;
                ans[x[i]].F = v[x[i]][a - 2];
                ans[x[i]].S = v[x[i]][a - 1];
                //接下來要刷新tmp
                tmp = i;
                cnt++;
                last = v[x[i]][a - 1];
            }
        }
        fr(j, 1, mx)
        {
            vector<int> vv[n + 1];
            if (cnt == n)
                break;
            int tmp = -1, last = -1;
            fr(i, 0, n * k)
            {
                vv[x[i]].push_back(i);
                int a = vv[x[i]].size();
                if (a > 1 && vv[x[i]][a - 2] > tmp)
                {
                    if (ans[x[i]].F != -1 && ans[x[i]].S != -1)
                        continue;
                    ans[x[i]].F = vv[x[i]][a - 2];
                    ans[x[i]].S = vv[x[i]][a - 1];
                    //接下來要刷新tmp

                    tmp = i;
                    cnt++;
                }
            }
            fr(i, 1, n + 1) vv[i].clear();
        }
        fr(i, 1, n + 1)
        {
            cout << ans[i].F + 1 << " " << ans[i].S + 1 << endl;
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
        END
    }
    return 0;
}