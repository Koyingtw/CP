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
#define MAXN 55
#define MAXM 1000005 
int n, m;
int x[MAXN], pre[MAXN], dp[MAXN][2][2];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
    }
    dp[0][1][0] = dp[0][1][1] = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cmax(dp[i][0][0], dp[j - 1][1][0] + x[i]);
            cmax(dp[i][1][1], dp[j - 1][0][1] + x[i]);
        }
        dp[i][0][1] = pre[i] - dp[i][0][0];
        dp[i][1][0] = pre[i] - dp[i][1][1];
    }
    cout << dp[n][0][0] << ' ' << dp[n][0][1] << endl;
    cout << dp[n][1][0] << ' ' << dp[n][1][1] << endl;
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