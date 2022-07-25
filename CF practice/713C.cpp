#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 3005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int dp[MAXN][MAXN];

void sol() {
	cin >> n;
    vector<int> y;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] -= i;
        y.pb(x[i]);
    }
    sort(all(y));
    y.erase(unique(all(y)), y.end());

    MEM(dp, 0x3f);

    for (int j = 0; j < y.size(); j++)
        dp[0][j] = min(dp[0][j - 1 + (j == 0)], abs(x[0] - y[j]));

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < y.size(); j++) {
            dp[i][j] = min(dp[i][j - 1 + (j == 0)], dp[i - 1][j] + abs(x[i] - y[j]));
        }
    }
    int ans = INF;
    for (int i = 0; i < y.size(); i++)
        cmin(ans, dp[n - 1][i]);
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