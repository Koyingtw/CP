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
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
int bit[MAXN];

void update(int id, int value)
{
    while (id < MAXN)
    {
        bit[id] += value;
        id += lowbit(id);
    }
    return;
}
int query(int id)
{
    int sum = 0;
    while (id)
    {
        sum += bit[id];
        id -= lowbit(id);
    }
    return sum;
}
void sol()
{
    vector<pair<string, int>> v;
    string s;
    set<int> st;
    map<int, int> m;
    int n;
    while (cin >> s && s != "exit")
    {
        cin >> n;
        v.push_back({s, n});
        st.insert(n);
    }
    int origin[st.size() + 1];
    bool has[st.size() + 1];
    MEM(bit, 0);
    MEM(has, 0);
    int cnt = 1;
    for (int i : st)
    {
        m[i] = cnt;
        origin[cnt] = i;
        cnt++;
    }
    int now = 0;
    for (auto it : v)
    {
        if (it.F == "insert")
            if (has[m[it.S]] == false)
            {
                update(m[it.S], 1);
                has[m[it.S]] ^= 1;
                now++;
            }
        if (it.F == "remove")
            if (has[m[it.S]] == true)
            {
                update(m[it.S], -1);
                has[m[it.S]] ^= 1;
                now--;
            }
        if (it.F == "ask")
        {
            if (now < it.S || it.S < 1)
            {
                cout << "error" << endl;
                continue;
            }
            int l = 1, r = MAXN;
            int mid = (l + r) >> 1;
            int ans = INF;
            while (l < r)
            {
                mid = (l + r) >> 1;
                int qq = query(mid);
                if (qq < it.S)
                    l = mid + 1;
                else
                    r = mid;
                if (qq == it.S)
                {
                    ans = min(ans, mid);
                }
            }

            cout << origin[l] << endl;
        }
    }
    //stop
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