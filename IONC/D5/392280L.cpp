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
int n, k, c;
int x[MAXN];
int dp[MAXN];
int dpp[2][30];
int last[30];

void sub1() {
    MEM(dp, 0x3f);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        // dp[i] = dp[i - 1] + abs(x[i] - x[i - 1]);
        for (int j = 1; j < i; j++)
            cmin(dp[i], dp[j] + abs(x[i] - x[j]) + c * (i - j - 1));
        cmin(dp[i], c * (i - 1));
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        cmin(ans, dp[i] + c * (n - i));
    }
    cout << ans << endl;
}

void sub2() {
    MEM(dpp, 0x3f);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cmin(dp[i % 2][i], dp[(i - 1) % 2][i] + abs(x[i] - j) + c * (i - last[x[i]]));
        }
        cmin(dpp[i % 2][i], c * (i - 1));
        last[x[i]] = i;
    }
    cout << dpp[n % 2][x[n]] << endl;
}

void sol() {
	cin >> n >> k >> c;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    if (n <= 1000) {
        sub1();
        return;
    }
    if (k <= 26) {
        sub2();
        return;
    }
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