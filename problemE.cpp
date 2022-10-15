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
#define MAXN 5005
#define MAXM 1000005 
int n, m, c;
int dp[2][MAXN], f[MAXN];

int fpow(int a, int b) {
    if (b < 0)
        return 1;
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % P;
        a = (a * a) % P;
        b >>= 1;
    }
    return res;
}

int p[MAXN];


void sol() {
    cin >> n >> m >> c;
    dp[0][0] = 1;
    p[0] = 1;
    for (int i = 1; i <= m; i++) {
        p[i] = p[i - 1] * (c + 1);
        p[i] %= P;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= m; j++) {
            sum += dp[1 - i % 2][j - 1] % P;
            sum %= P;
            dp[i % 2][j] = sum * p[j - i] % P;
            ans += dp[i % 2][j];
            ans %= P;
        }
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