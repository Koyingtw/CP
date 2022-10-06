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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, k;
int dp[2][MAXN], ans[MAXN];

void sol() {
	cin >> n >> k;
    dp[0][0] = 1;
    // int cur = 1;
    for (int i = 0; i <= n; i += k, k++) {
        vector<int> sum(k, 0);
        for (int j = i + k; j <= n; j++) {
            sum[j % k] += dp[0][j - k];
            sum[j % k] %= P;
            dp[1][j] = sum[j % k];
        }
        swap(dp[0], dp[1]);

        for (int j = i + k; j <= n; j++) {
            ans[j] += dp[0][j];
            ans[j] %= P; 
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
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