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
/******************************************************************************/

void sol()
{
    int n, a, b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    if (b < 0)
    {
        int cnt = 1;
        int sum = 0;
        int ans = a * n;
        vector<int> v;
        fr(i, 1, n)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                v.push_back(cnt);
                if (s[i - 1] == '0')
                {
                    sum++;
                }
                cnt = 1;
            }
        }
        v.push_back(cnt);
        if (s[n - 1] == '0')
            sum++;

        if (sum < v.size() - sum) //0
        {
            ans += b * (sum + 1);
        }
        else //0
        {
            ans += b * ((v.size() - sum) + 1);
        }
        cout << ans << endl;
        //fr(i, 0, v.size()) cout << v[i] << endl;
    }
    else
    {
        cout << (a + b) * n << endl;
    }
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
            sol();
    return 0;
}