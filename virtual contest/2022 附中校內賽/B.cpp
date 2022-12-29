#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 200005
int n, q;

void sol() {
    set<int> st;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    vector<int> ans;

    int op, now = 1;
    while (q--) {
        cin >> op;
        if (op == 1) {
            if (st.lower_bound(now) == st.begin())
                now = *(--st.end());
            else
                now = *(--st.lower_bound(now));
        }
        if (op == 2) {
            if (st.upper_bound(now) == st.end())
                now = *(st.begin());
            else
                now = *st.upper_bound(now);
        }
        if (op == 3) {
            ans.push_back(now);
            st.erase(now);
            if (st.size()) {
                if (st.upper_bound(now) == st.end())
                    now = *(st.begin());
                else
                    now = *st.upper_bound(now);
            }
        }
        // cout << now << endl;
    }

    for (int it: ans)
        cout << it << ' ';
    cout << endl;
}

signed main() {
    Koying;
    sol();
    return 0;
}