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
    int n;
    while (cin >> n)
    {
        int x[n];
        set<int> s;
        map<int, int> m;
        fr(i, 0, n)
        {
            cin >> x[i];
            s.insert(x[i]);
        }
        int cnt = 0;
        for (int i : s)
        {
            m[i] = cnt;
            cnt++;
        }
        fr(i, 0, n)
        {
            cout << m[x[i]] << " ";
        }
        cout << endl;
    }
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