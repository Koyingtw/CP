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
    string n, m;
    while (cin >> n >> m)
    {
        set<char> s;
        for (int i = 0; i < m.size(); i++)
        {
            s.insert(m[i]);
        }
        int a = 0, b = 0;
        for (int i = 0; i < n.size(); i++)
        {
            if (m[i] == n[i])
            {
                a++;
                continue;
            }
            else if (s.count(n[i]))
            {
                //cout << n[i] << endl;
                b++;
            }
        }
        cout << a << " " << b << endl;
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