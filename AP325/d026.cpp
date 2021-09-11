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
        st.push(s[0]);
        bool yes = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if (st.top() == '(')
            {
                if (s[i] == ')')
                {
                    st.pop();
                    continue;
                }
                else if (s[i] == ']' || s[i] == '}')
                {
                    yes = 0;
                    break;
                }
            }
            if (st.top() == '[')
            {
                if (s[i] == ']')
                {
                    st.pop();
                    continue;
                }
                else if (s[i] == ')' || s[i] == '}')
                {
                    yes = 0;
                    break;
                }
            }
            if (st.top() == '{')
            {
                if (s[i] == '}')
                {
                    st.pop();
                    continue;
                }
                else if (s[i] == ']' || s[i] == ')')
                {
                    yes = 0;
                    break;
                }
            }
            st.push(s[i]);
        }
        if (st.size() != 0)
            yes = 0;
        if (yes)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
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