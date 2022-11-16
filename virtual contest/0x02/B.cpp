#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#if !LOCAL
#define endl '\n'
#endif

const int INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 605

int n, k;
pii x[MAXN];

void sol() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i].F >> x[i].S;
    }
    sort(x, x + n, [&](auto _a, auto _b) {
        if (_a.S != _b.S)
            return _a.S < _b.S;
        return _a.F < _b.F;
    });

    int ans = INF;

    for (int i = (k == 0 ? -1 : 0); i < (k == 0 ? 0 : n); i++) {
        for (int j = (k <= 1 ? i : i + 1); j < (k <= 1 ? i + 1 : n); j++) {
            int now = -1, cnt = 0;
            for (int l = 0; l < n; l++) if (i != l && j != l) {
                if (now == -1) {
                    cnt = 1, now = l;
                }

                if (x[l].F > x[now].S) {
                    now = l;
                    cnt++;
                }
                // cout << now << endl;
            }
            cmin(ans, cnt);
        }
    }
    cout << ans << endl;
}

signed main() {
    int _ = 1;
    while (_--) {
        sol();
    }
    return 0;
} 