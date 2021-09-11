#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/

#define data node

struct data
{
    string st;
    int sum;
    int id;
};

bool cmp(data a, data b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.st.size() != b.st.size())
        return a.st.size() < b.st.size();
    else
        return a.id < b.id;
}

void sol()
{
    int n;
    while (cin >> n)
    {
        cin.ignore();
        data s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].st;
            s[i].id = i;
            s[i].sum = 0;
            set<char> sc{s[i].st[0]};
            for (int j = 1; j < s[i].st.size(); j++)
            {
                s[i].sum += abs(s[i].st[j] - s[i].st[j - 1]);
                if (sc.count(s[i].st[j]))
                {
                    s[i].sum--;
                }
                else
                    sc.insert(s[i].st[j]);
            }
            s[i].sum -= s[i].st.size();
        }
        sort(s, s + n, cmp);
        int ans[n];
        for (int i = 0; i < n; i++)
        {
            ans[s[i].id] = i + 1;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " " << s[ans[i] - 1].sum << endl;
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