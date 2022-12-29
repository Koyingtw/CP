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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int dp[3][MAXN], from[3][MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] += x[i - 1];
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = m; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            from[i][j] = from[i][j - 1];
        
            if (dp[i][j] < dp[i - 1][j - m] + x[j] - x[j - m]) {
                cmax(dp[i][j], dp[i - 1][j - m] + x[j] - x[j - m]);
                from[i][j] = j - m + 1;
            }
        }
    }

    cout << from[1][from[2][n] - 1] << ' ' << from[2][n] << endl;
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