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
#define stop return 0;
#else
#define stop         \
    system("pause"); \
    return 0;
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int n, m;
    while (cin >> n >> m)
    {
        int x[n], dsu[n], cnt[n], y[m];
        int mx = 0, mn = INF;
        pr ans = {0, 0};
        multiset<int> s;
        MEM(cnt, 0);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < m; i++)
            cin >> y[i];
        for (int i = 0; i < n; i++)
        {
            if (i)
            {
                if (x[i] && x[i - 1] == 1)
                {
                    dsu[i] = dsu[i - 1];
                    cnt[dsu[i]]++;
                }
                else if (x[i])
                {
                    dsu[i] = i;
                    cnt[i]++;
                }
                else
                    dsu[i] = i;
            }
            else
            {
                if (x[i])
                {
                    dsu[i] = i;
                    cnt[i]++;
                }
                else
                    dsu[i] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (x[i] && dsu[i] == i)
            {
                s.insert(cnt[i]);
            }
        }
        ans.F += *prev(s.end(), 1);
        ans.S += *s.begin();
        for (int i = 0; i < m; i++)
        {
            int in = y[i] - 1;

            if (in)
            {
                if (x[in + 1] && x[in - 1])
                {
                    if (cnt[dsu[in - 1]] > cnt[dsu[in + 1]])
                    {
                        s.erase(s.find(cnt[dsu[in - 1]]));
                        s.erase(s.find(cnt[dsu[in + 1]]));

                        cnt[dsu[in - 1]] += cnt[dsu[in + 1]] + 1;
                        dsu[in] = dsu[in - 1];
                        dsu[in + 1] = dsu[in - 1];
                        s.insert(cnt[dsu[in]]);
                    }
                    else
                    {
                        s.erase(s.find(cnt[dsu[in - 1]]));
                        s.erase(s.find(cnt[dsu[in + 1]]));

                        cnt[dsu[in + 1]] += cnt[dsu[in - 1]] + 1;
                        dsu[in] = dsu[in + 1];
                        dsu[in - 1] = dsu[in + 1];
                        s.insert(cnt[dsu[in]]);
                    }
                }
                else if (x[in - 1])
                {
                    s.erase(s.find(cnt[dsu[in - 1]]));

                    cnt[dsu[in - 1]]++;
                    dsu[in] = dsu[in - 1];
                    s.insert(cnt[dsu[in]]);
                }
                else if (x[in + 1])
                {
                    s.erase(s.find(cnt[dsu[in + 1]]));

                    cnt[dsu[in + 1]]++;
                    dsu[in] = dsu[in + 1];
                    s.insert(cnt[dsu[in]]);
                }
                else if (x[in])
                {
                    s.erase(s.find(cnt[in]));
                    cnt[in]++;
                    s.insert(cnt[in]);
                }
                else
                {
                    cnt[in]++;

                    s.insert(cnt[in]);
                }
            }
            else
            {
                if (x[in + 1])
                {
                    s.erase(s.find(cnt[dsu[in + 1]]));

                    cnt[dsu[in + 1]]++;
                    dsu[in] = dsu[in + 1];
                    s.insert(cnt[dsu[in]]);
                }
                else if (x[in])
                {
                    s.erase(s.find(cnt[in]));
                    cnt[in]++;
                    s.insert(cnt[in]);
                }
                else
                {
                    cnt[in]++;

                    s.insert(cnt[in]);
                }
            }

            multiset<int>::iterator it = s.end();
            ans.F += *(s.rbegin());
            ans.S += *(s.begin());
            // cout << ans.F << endl
            //      << ans.S << endl;
            x[in] = 1;
        }
        cout << ans.F << endl
             << ans.S << endl;
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