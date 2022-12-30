#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9 + 7;

using namespace std;

#define MAXN 100005
int n, m;
int dp[MAXN][2][2];

struct input {
    vector<int> v;
    int k, id;
    int sum, mxpre, mnpre;
    int mxsuf, mnsuf;

    input(): sum(0), mxpre(-INF), mnpre(0), mxsuf(-INF) {}
} x[MAXN];

void sol() {
    cin >> n;

    int ans = -INFLL;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i].k;
        x[i].id = i;
        x[i].v.resize(x[i].k);
        int sum = 0;
        for (int j = 0; j < x[i].k; j++) {
            cin >> x[i].v[j];
            sum += x[i].v[j];
            cmax(ans, sum - x[i].mnpre);
            cmin(x[i].mnpre, sum);
            cmax(x[i].mxpre, sum);
        }
        x[i].sum = sum;

        sum = 0;
        for (int j = x[i].k - 1; j >= 0; j--) {
            sum += x[i].v[j];
            cmax(x[i].mxsuf, sum);
            cmin(x[i].mnsuf, sum);
        }
    }

    if (n == 1) {
        cout << ans << endl;
        return;
    }

    bitset<MAXN> used;
    int tmp = 0, usedcnt = 0;
    // sort(x, x + n, [&](auto _a, auto _b) {
    //     if (_a.sum > 0 || _b.sum > 0)
    //         return _a.sum > _b.sum;
        
    // });

    // for (int i = 0; i < n; i++) {
    //     if (x[i].sum > max(x[i].mxpre, x[i].mxsuf) && x[i].sum > 0 && usedcnt < n - 2) {
    //         used[x[i].id] = true;
    //         usedcnt++;
    //         tmp += x[i].sum;
    //     }
    // }

    for (int i = 0; i < n; i++) {
        // cout << x[i].sum << ' ' << x[i].mxsuf << ' ' << x[i].mxpre << ' ' << x[i].sum << endl;
        if (i == 0) {
            dp[i][0][0] = x[i].sum;
            dp[i][0][1] = x[i].mxsuf;
            dp[i][1][0] = x[i].mxpre;
            dp[i][1][1] = x[i].sum;
        }
        else {
            dp[i][0][0] = dp[i - 1][0][0];
            dp[i][0][1] = dp[i - 1][0][1];
            dp[i][1][0] = dp[i - 1][1][0];
            dp[i][1][1] = dp[i - 1][1][1];
            cmax(dp[i][0][0], max(dp[i - 1][0][0] + x[i].sum, x[i].sum));

            cmax(dp[i][0][1], max(dp[i - 1][0][1] + x[i].sum, x[i].mxsuf));
            cmax(dp[i][0][1], dp[i - 1][0][0] + x[i].mxsuf);

            cmax(dp[i][1][0], max(dp[i - 1][1][0] + x[i].sum, x[i].mxpre));
            cmax(dp[i][1][0], dp[i - 1][0][0] + x[i].mxpre);

            cmax(dp[i][1][1], dp[i - 1][1][1] + x[i].sum);
            cmax(dp[i][1][1], max(dp[i - 1][1][0] + x[i].mxsuf, dp[i - 1][0][1] + x[i].mxpre));
        }
        cmax(ans, dp[i][0][0]);
        cmax(ans, dp[i][0][1]);
        cmax(ans, dp[i][1][0]);
        cmax(ans, dp[i][1][1]);
    }
    cout << ans << endl;
}

/*
4
3 1 4 -6
2 -1 -3
6 6 -11 5 -13 3 12
4 14 -7 -3 15
*/

signed main() {
    Koying;
    sol();
    return 0;
}