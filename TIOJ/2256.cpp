#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 45
#define MAXM 1000005 
int n, m;
int p[MAXN], s[MAXN], x[MAXN], xsum[MAXN], ssum[MAXN];
int r[MAXN][MAXN];
int dp[MAXN][MAXN * MAXN];


void sol() {
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] = p[i - 1] + p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ssum[i] = ssum[i - 1] + s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sum += x[i];
        xsum[i] = xsum[i - 1] + x[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cin >> r[i][j];
    }

    MEM(dp, 0x3f);
    // MEM(dp[0], 0);
    dp[0][0] = 0;

    int ans = ((sum * p[n]) <= m ? 0 : -1);

    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int cnt = 0;
            int pp = (xsum[n] - xsum[j]) * (p[i] - p[j]);
            int ss = (xsum[i] - xsum[j]) * s[i];
            // cout << pp << ' ' << ss << endl;

            for (int l = j + 1; l <= i; l++)
                cnt += r[i][l];

            for (int k = 0; k <= xsum[i]; k++) if (k + cnt <= xsum[i]) {
                cmin(dp[i][k + cnt], dp[j][k] + pp + ss);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 0; j--) {
            // cout << dp[i][j] << ' ';
            if (dp[i][j] + (xsum[n] - xsum[i]) * (p[n] - p[i]) <= m) {
                cmax(ans, j);
            }
        }
        // cout << endl;
    }


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