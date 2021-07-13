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
    int n, m;
    cin >> n >> m;
    string s[n];
    map<char, int> mp[m];
    fr(i, 0, n)
    {
        string a;
        cin >> a;
        fr(j, 0, m)
        {
            mp[j][a[j]]++;
        }
    }
    fr(i, 0, n - 1)
    {
        string a;
        cin >> a;
        fr(j, 0, m)
        {
            mp[j][a[j]]--;
        }
    }
    fr(i, 0, m)
    {
        fr(j, 0, 26)
        {
            if (mp[i]['a' + j] == 1)
            {
                cout << char('a' + j);
            }
        }
    }
    cout << endl;
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