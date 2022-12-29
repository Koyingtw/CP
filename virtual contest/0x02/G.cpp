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

#define MAXN 105

int n, x, d;
int ans[MAXN];

void sol() {
    cin >> n >> x >> d;
    ans[0] = -INF;
    ans[1] = 1;
    for (int i = 2; i <= n / 2; i++) {
        ans[i] = ans[i - 1] + d;
    }
    ans[n / 2 + 1] = x;
    if (ans[n / 2 + 1] - ans[n / 2] < d) {
        cout << -1 << endl;
        return;
    }
    for (int i = n / 2 + 2; i <= n; i++) {
        ans[i] = ans[i - 1] + d;
        if (ans[i] > 1e9) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

signed main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }
    return 0;
} 