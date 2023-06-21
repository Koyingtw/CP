#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 505 
int n, m, k;
int x[MAXN];
int dp[MAXN][2];
int pre[MAXN];
deque<pii> dq;

void sol() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
    }

    int ans = 0;

    for (int j = 1; j <= m; j++) {
        while (!dq.empty())
            dq.pop_back();
        dq.push_back({0, 0});
        for (int i = 1; i <= n; i++) {
            dp[i][j % 2] = dp[i - 1][j % 2];
            // cout << "a" << endl;

            while (!dq.empty() && pre[i] - pre[dq.front().S] > k) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                cmax(dp[i][j % 2], dq.front().F + pre[i]);
                // cout << dq.front().S << ' ' << i << ' ' << dp[i][j % 2] << ' ' << dp[dq.front().S][j - 1] << endl;
            }

            while (!dq.empty() && dp[dq.back().S][j - 1] <= dp[i][(j - 1) % 2] - pre[i]) {
                dq.pop_back();
            }
            dq.push_back({dp[i][(j - 1) % 2] - pre[i], i});
            // cout << dp[i][(j - 1) % 2] - pre[i] << ' ';

            cmax(ans, dp[i][j % 2]);

            // while (!dq.empty() && )
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         dp[i][j % 2] = dp[i - 1][j];


    //         // brute
    //         // for (int l = 0; l < i; l++) {
    //         //     if (pre[i] - pre[l] <= k) {
    //         //         cmax(dp[i][j % 2], dp[l][j - 1] + pre[i] - pre[l]);
    //         //     }
    //         // }
    //         cmax(ans, dp[i][j % 2]);
    //     }
    // }
    cout << ans << endl;

}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}