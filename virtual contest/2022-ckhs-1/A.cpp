#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define MEM(x, n) memset(x, n, sizeof(x))
#define pii pair<int, int>
#if !LOCAL
#pragma GCC optimize("Ofast, unroll-all-loops")
#define endl '\n'
#endif
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

#define MAXN 200005
#define MAXM 1000005

int n, m;
int cnt[10];

void sol() {
    for (int i = 0, k, d; i < 6; i++) {
        cin >> k;
        while (k--) {
            cin >> d;
            cnt[d]++;
        }
    }
    int ans = 1;
    for (int i = 1; i <= 6; i++) {
        ans *= (6 - cnt[i]);
        // cout << 6 - cnt[i] << ' ';
    }
    cout << ans << endl;
}

signed main() {
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--) 
    {
        sol();
    }
    return 0;
}