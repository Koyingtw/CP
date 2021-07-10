/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

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

void OUT(string s)
{
    cout << s;
    return;
}
int x[200005];
vector<int> v[200005];
int ans = 0;
set<int> s;
int dfs(int depth, int i, int dp[])
{
    s.insert(i);

    for (int it : v[i])
    {
        if (x[it] >= x[i] && s.count(it) == 0)
        {
            dfs(depth + 1, it, dp);
        }
    }
    return ans = max(depth, ans);
}

void sol()
{
    int n;
    while (cin >> n)
    {
        fr(i, 0, n)
        {
            cin >> x[i + 1];
        }
        fr(i, 0, n - 1)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        int dp[n + 1];
        MEM(dp, 127);
        dp[0] = -INF;
        fr(i, 1, 200005)
        {
            if (s.count(i) == 0)
                dfs(1, i, dp);
        }
        cout << ans << endl;
    }
}

void sol1()
{
    int n;
    while (cin >> n)
    {
        bool yes = 1;
        fr(i, 1, n + 1)
        {
            cin >> x[i];
            if (i > 1 && x[i] != x[i - 1])
                yes = 0;
        }
        fr(i, 0, n - 1)
        {
            int a, b;
            cin >> a >> b;
        }
        if (yes)
        {
            cout << n << endl;
            continue;
        }
        int dp[n + 1];
        MEM(dp, 127);
        dp[0] = -INF;
        fr(i, 1, n + 1)
        {
            rf(j, i, 1)
            {
                if (dp[j - 1] <= x[i])
                {
                    dp[j] = min(x[i], dp[j]);
                }
            }
        }
        rf(i, n, 0)
        {
            if (dp[i] < 10000000000)
            {
                cout << i << endl;
                break;
            }
        }
    }
}

signed main()
{
    Koying
    sol1();
    return 0;
}