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
#if ONLINE_JUDGE
#define END return 0;
#else
#define END   \
    return 0; \
    system("pause");
#endif
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
struct in
{
    int a, b, id;
};
bool cmp(in x, in y)
{
    if (x.a != y.a)
        return x.a < y.a;
    else
        return x.b < y.b;
}
void sol()
{
    int n;
    while (cin >> n)
    {
        in x[n];
        pr st[n], fin[n];
        int ans[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i].a >> x[i].b;
            x[i].b++;
            x[i].id = i;
            st[i] = {x[i].a, i}, fin[i] = {x[i].b, i};
        }
        sort(st, st + n);
        sort(fin, fin + n);
        queue<int> q;
        int mx = 0;
        int f = 0, s = 0;
        for (; f < n; f++)
        {
            for (; fin[s].F <= st[f].F && s < n; s++)
            {
                q.push(ans[fin[s].S]);
            }
            if (q.size() == 0)
            {
                mx++;
                q.push(mx);
            }
            ans[st[f].S] = q.front();
            q.pop();
        }
        cout << mx << endl;
        for (int it : ans)
            cout << it << " ";
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
    }
    return 0;
}