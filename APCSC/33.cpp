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

void sol()
{
    int t;
    while (cin >> t)
    {
        int a, b;
        set<int> s;
        while (t--)
        {
            cin >> a;
            if (a == 1)
            {
                cin >> b;
                s.insert(b);
            }
            else if (a == 2)
            {
                cin >> b;
                if (s.count(b))
                    s.erase(b);
                else
                    cout << "error" << endl;
            }
            else if (a == 3)
                cout << s.size() << endl;
            else if (a == 4)
            {
                if (s.size() == 0)
                    cout << "error" << endl;
                else
                    cout << *s.begin() << endl;
            }
            else
            {
                if (s.size() == 0)
                    cout << "error" << endl;
                else
                    cout << *s.rbegin() << endl;
            }
        }
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