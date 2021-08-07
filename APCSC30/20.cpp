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
    string s;
    while (cin >> s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.size() && s[i] == st.top())
            {
                st.pop();
            }
            else
                st.push(s[i]);
        }
        stack<char> ans;
        while (st.size())
        {
            ans.push(st.top());
            st.pop();
        }
        while (ans.size())
        {
            cout << ans.top();
            ans.pop();
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
        END
    }
    return 0;
}