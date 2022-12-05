#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
// #define max(a, b) (a > b ? a : b)
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 205
#define MAXM 1000005 
int n, m;
array<int, 2> x[MAXN];
int dp[MAXN][MAXN][3];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i][0] >> x[i][1];

    int ans = 0;

    MEM(dp, -0x3f);
    MEM(dp[0][0], 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(m, i); j++) {
            dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2]}) + x[i][0] + x[i][1];
            if (j) {
                cmax(dp[i][j][1], dp[i - 1][j - 1][1]);
                cmax(dp[i][j][2], dp[i - 1][j - 1][2]);
                cmax(dp[i][j][1], dp[i - 1][j - 1][0]);
                cmax(dp[i][j][2], dp[i - 1][j - 1][0]);
            }
            dp[i][j][1] += x[i][0];
            dp[i][j][2] += x[i][1];
        }
        cmax(ans, *max_element(dp[i][m], dp[i][m] + 3));
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