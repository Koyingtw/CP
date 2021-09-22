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
    int x, n;
    while (cin >> x >> n)
    {
        int a;
        multiset<int> s;
        set<int> st;
        s.insert(x);
        st.insert(0);
        st.insert(x);
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            auto find = st.upper_bound(a);
            auto pre = prev(find);
            auto it = s.lower_bound(*find - *pre);
            s.erase(it);
            auto in = st.insert(a);
            s.insert(*find - a);
            s.insert(a - *pre);
            cout << *prev(s.end()) << " ";
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
    {
        sol();
    }
    return 0;
}