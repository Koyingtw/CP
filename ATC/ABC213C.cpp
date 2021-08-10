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
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        pr x[k];
        int mxx, mxy;
        set<int> s1, s2;
        map<int, int> mp1, mp2;
        mxx = mxy = INF;
        for (int i = 0; i < k; i++)
        {
            cin >> x[i].F >> x[i].S;
            s1.insert(x[i].F);
            s2.insert(x[i].S);
        }
        int cnt = 1;
        for (int i : s1)
        {
            mp1[i] = cnt;
            cnt++;
        }
        cnt = 1;
        for (int i : s2)
        {
            mp2[i] = cnt;
            cnt++;
        }
        for (int i = 0; i < k; i++)
        {
            cout << mp1[x[i].F] << " " << mp2[x[i].S] << endl;
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