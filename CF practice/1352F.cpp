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
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

void sol()
{
    int a, b, c;
    cin >> a >> b >> c;
    string ans;
    if (a)
    {
        ans += '0';
        while (a--)
            ans += '0';
        if (b && b % 2)
        {
            while (b--)
            {
                if (ans[ans.size() - 1] == '0')
                    ans += '1';
                else
                    ans += '0';
            }
            while (c--)
                ans += '1';
        }
        else if (b)
        {
            fr(i, 0, b - 1)
            {
                if (ans[ans.size() - 1] == '0')
                    ans += '1';
                else
                    ans += '0';
            }
            while (c--)
                ans += '1';
            ans += '0';
        }
    }
    else
    {
        if (b % 2)
        {
            ans += '0';
            while (b--)
            {
                if (ans[ans.size() - 1] == '0')
                    ans += '1';
                else
                    ans += '0';
            }
            while (c--)
                ans += '1';
        }
        else
        {
            ans += '1';
            while (b--)
            {
                if (ans[ans.size() - 1] == '0')
                    ans += '1';
                else
                    ans += '0';
            }
            while (c--)
                ans += '1';
        }
    }
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
            END
        }
    return 0;
}