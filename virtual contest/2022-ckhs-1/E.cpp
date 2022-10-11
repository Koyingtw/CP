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

const int P = 1e9 + 7;

#define MAXN 200005
#define MAXM 1000005

int n;
int x[MAXN], dp[MAXN], cnt[MAXN], sum = 0;

void sol() {
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cnt[x[0]] = sum = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] * 2 - cnt[x[i]];
        dp[i] %= P;
        dp[i] += P;
        dp[i] %= P;
        cnt[x[i]] += dp[i - 1] - cnt[x[i]];
        cnt[x[i]] %= P;
        cnt[x[i]] += P;
        cnt[x[i]] %= P;
    }
    cout << dp[n - 1] << endl;
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