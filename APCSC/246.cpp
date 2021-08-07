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
#define END cout.flush();
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

int f(char c)
{
    return (c < 'z' && c >= 'a');
}

void sol()
{
    int n;
    string s;
    while (cin >> n)
    {
        cin.ignore();
        cin >> s;
        vector<int> v;
        if (s.size() == 1)
        {
            if (n == 1)
                cout << 1 << endl;
            continue;
        }
        int cnt = 1;

        for (int i = 1; i < s.size(); i++)
        {
            if (f(s[i]) == f(s[i - 1]))
                cnt++;
            else
            {
                v.push_back(cnt);
                cnt = 1;
            }
        }

        v.push_back(cnt);
        int ans = 0;
        cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == n)
            {
                cnt++;
            }
            else
            {
                if (i && v[i - 1] == n && v[i] > n)
                {
                    cnt++;
                }
                ans = max(ans, cnt);
                cnt = 0;
                if (v[i] > n && i < n - 1 && v[i + 1] == n)
                    cnt++;
            }
        }
        ans = max(ans, cnt);
        cout << ans * n << endl;
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