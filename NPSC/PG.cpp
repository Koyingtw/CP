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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
int dp[MAXN][MAXN], x[MAXN], y[MAXN], prex[MAXN], prey[MAXN];
int ans[MAXN][MAXN];
pii from[MAXN][MAXN];



void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        prex[i] = prex[i - 1] + x[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> y[i];
        prey[i] = prey[i - 1] + y[i];
    }


    MEM(dp, 0x3f);
    MEM(ans, 0x3f);
    
    dp[0][0] = 0;
    ans[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i - 1 >= 0 && dp[i - 1][j] + x[i] >= 0 && dp[i - 1][j] < INF)  {
                if (dp[i][j] >= dp[i - 1][j] + x[i]) {
                    dp[i][j] = dp[i - 1][j] + x[i];
                    if (dp[i][j] == dp[i - 1][j] + x[i]) {
                        if (ans[i][j] > max(ans[i - 1][j], dp[i - 1][j])) {
                            ans[i][j] = max(dp[i - 1][j] + x[i], ans[i - 1][j]);
                            from[i][j] = {i - 1, j};        
                        }
                    }
                    else {
                        ans[i][j] = max(dp[i - 1][j] + x[i], ans[i - 1][j]);
                        from[i][j] = {i - 1, j};
                    }
                }
            }
            if (j - 1 >= 0 && dp[i][j - 1] + y[j] >= 0 && dp[i][j - 1] < INF) {
                if (dp[i][j] >= dp[i][j - 1] + y[j]) {
                    dp[i][j] = dp[i][j - 1] + y[j];
                    if (dp[i][j] == dp[i][j - 1] + y[j]) {
                        if (ans[i][j] > max(ans[i][j - 1], dp[i][j - 1])) {
                            ans[i][j] = max(dp[i][j - 1] + y[j], ans[i][j - 1]);
                            from[i][j] = {i, j - 1};        
                        }
                    }
                    else {
                        ans[i][j] = max(dp[i][j - 1] + y[j], ans[i][j - 1]);
                        from[i][j] = {i, j - 1};
                    }
                }
            }
        }
    }


    int mx = 0;
    int xx = n, yy = m;
    while (xx || yy) {
        cmax(mx, dp[xx][yy]);
        pii p = from[xx][yy];
        xx = p.F;
        yy = p.S;
    }
    cout << (mx < INF ? mx : -1) << endl;
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