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
    int n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    int ans = n + 1;
    for (int c = 0, l, r, cnt; c < 26; c++)
    {
        l = 0, r = n - 1;
        cnt = 0;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++, r--;
            }
            else if (s[r] == (c + 'a'))
            {
                cnt++;
                r--;
            }
            else if (s[l] == (c + 'a'))
            {
                cnt++;
                l++;
            }
            else
            {
                cnt = n + 1;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    if (ans > n)
        cout << -1 << endl;

    else
        cout << ans << endl;
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}