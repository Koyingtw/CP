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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 27
#define MAXM 200005 
int n, m;
int dp[2][MAXN][MAXN];
int x[MAXM], pre[MAXN];

void sol() {
	cin >> m >> n;
    MEM(dp, 0x3f);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[0][i][j] = 0;
    for (int i = 1; i <= m; i++) 
        cin >> x[i];

    for (int i = 1; i <= m; i++) {
        int pos = x[i];
        // int mn = INF;
        for (int j = 1; j <= n; j++) { //left
            for (int k = 1; k <= n; k++) {
                cmin(dp[i % 2][j][pos], dp[(i - 1) % 2][j][k] + abs(k - pos));
                // cmin(mn, dp[i][j][pos]);
            }
        }
        // cout << mn << " ";
        // mn = INF;
        for (int j = 1; j <= n; j++) { //right
            for (int k = 1; k <= n; k++) {
                cmin(dp[i % 2][pos][j], dp[(i - 1) % 2][k][j] + abs(k - pos));
                // cmin(mn, dp[i][pos][j]);
            }
        }

        for (int j = 1; j <= n; j++) { //right
            for (int k = 1; k <= n; k++) {
                dp[(i - 1) % 2][j][k] = INF;
            }
        }
        
        // cout << mn << endl;
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        cmin(ans, dp[m % 2][i][x[m]]);
        cmin(ans, dp[m % 2][x[m]][i]);
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