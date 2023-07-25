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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN], pre[MAXN], dp[MAXN][21];

void sol() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
    }

    MEM(dp, 0x3f);
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][1] = pre[i] * pre[i];
        for (int j = 2; j <= m; j++) {
            for (int k = 1; k <= i; k++) {
                cmin(dp[i][j], dp[k - 1][j - 1] + (pre[i] - pre[k - 1]) * (pre[i] - pre[k - 1]));
            }
        }

        cout << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << *min_element(dp[n] + 1, dp[n] + m + 1) << endl;
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