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
    string s;
    vector<int> ans;
    cin >> s;
    fr(i, 0, s.size())
    {
        if (isdigit(s[i]))
        {
            ans.push_back(s[i] - '0');
        }
    }
    sort(ans.begin(), ans.end());
    fr(i, 0, ans.size() - 1)
    {
        cout << ans[i] << "+";
    }
    cout << ans[ans.size() - 1] << endl;
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