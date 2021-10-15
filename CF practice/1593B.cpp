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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    string s;
    cin >> s;
    int ans = s.size();
    int a = -1, b = -1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == '0' && s[j] == '0')
            {
                int tmp = j - i - 1 + s.size() - j - 1;
                ans = min(ans, tmp);
            }
            if (s[i] == '2' && s[j] == '5')
            {
                int tmp = j - i - 1 + s.size() - j - 1;
                ans = min(ans, tmp);
            }
            if (s[i] == '5' && s[j] == '0')
            {
                int tmp = j - i - 1 + s.size() - j - 1;
                ans = min(ans, tmp);
            }
            if (s[i] == '7' && s[j] == '5')
            {
                int tmp = j - i - 1 + s.size() - j - 1;
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
    {
        cin.ignore();
        while (t--)
        {
            sol();
        }
    }
    return 0;
}