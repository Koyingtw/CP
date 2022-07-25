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
#define MAXN 5005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int pre[MAXN];
int dp[MAXN];
int ans[MAXN];

void init() {
    for (int i = 0; i <= n; i++)
        dp[i] = ans[i] = -INF;
}

void sol() {
	cin >> n >> m;
    init();

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        pre[i + 1] = pre[i] + x[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cmax(dp[i], pre[j] - pre[j - i]);
            cmax(ans[0], dp[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cmax(ans[j], dp[i] + m * j);
    }
    for (int i = 0; i <= n; i++) {
        if (i)
            cmax(ans[i], ans[i - 1]);
        cout << max(ans[i], 0ll) << (" \n")[i == n];
    }
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}