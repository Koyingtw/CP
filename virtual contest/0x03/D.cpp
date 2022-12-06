#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define lowbit(x) (x & (-x))
#define pb push_back
#define pf push_front
#define MEM(x, n) memset(x, n, sizeof(x))
const int INF = 0x3f3f3f3f3f3f3f3f;

#if !LOCAL
#define endl '\n'
#endif

using namespace std;

#define MAXN 100005

int n, m, q;
pii x[MAXN];

set<int> st[4];
set<pii> ans;

void sol() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> x[i].F >> x[i].S;
    }
    x[q] = {INF, INF};

    function<bool(pii, pii)> cmp[] = {
        [&](pii _a, pii _b) {
            return _a.F < _b.F;
        },
        [&](pii _a, pii _b) {
            return _a.S < _b.S;
        },
        [&](pii _a, pii _b) {
            return _a.F + _a.S < _b.F + _b.S;
        },
        [&](pii _a, pii _b) {
            return _a.F - _a.S < _b.F - _b.S;
        }
    };


    for (int t = 0; t < 4; t++) {
        sort(x, x + q, cmp[t]);
        // cout << t << endl;
        for (int i = 0; i < q;) {
            // cout << x[i].F << ' ' << x[i].S << endl;
            for (int j = i + 1; j <= q; j++) {
                if (cmp[t](x[i], x[j]) || cmp[t](x[j], x[i]) || j == q) {
                    if (j - i > 1) {
                        for (int k = i; k < j; k++) {
                            ans.insert(x[k]);
                            // cout << x[k].F << ' ' << x[k].S << endl;
                        }
                    }
                    i = j;
                    break;
                }
            }
            // cout << i << endl;
        }
    }
    // cout << "OWO" << endl;


    cout << (ans.size() > 0 ? (int)ans.size() : (int)-1) << endl;
    for (auto it: ans)
        cout << it.F << ' ' << it.S << endl;
}

signed main() {
    Koying
    sol();
    return 0;
}