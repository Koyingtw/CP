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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 10005
#define MAXM 1000005 
int n, m;
int dp[MAXM][3];

void pre() {
    dp[1][0] = 1;
    dp[2][0] = 2;
    dp[2][1] = 1;
    dp[2][2] = 1;
    for (int i = 3; i < MAXM; i++) {
        dp[i][0] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] += dp[i - 1][2];
        dp[i][2] += dp[i - 1][1];
        if (i >= 2) {
            dp[i][0] += dp[i - 2][0];
            dp[i][1] += dp[i - 2][0];
            dp[i][2] += dp[i - 2][0];
        }
        dp[i][0] %= P;
        dp[i][1] %= P;
        dp[i][2] %= P;
    }
}

void sol() {
	cin >> n;
    cout << dp[n][0] << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    pre();
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}