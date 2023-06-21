#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e6+7;

using namespace std;
/******************************************************************************/
#define MAXN 105
#define MAXM 1000005 
int n, m;
int a[MAXN];
int dp[MAXN][MAXN];
int fac[MAXN];

void pre() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = fac[i - 1] * i % P;
}

int fpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return ans;
}

int C(int n, int m) {
    return fac[n] / fac[m] / fac[n - m];
    return fac[n] * fpow(fac[m] * fac[n - m] % P, P - 2) % P;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    MEM(dp, 0);
    
    for (int i = 0; i <= 0; i++)
        dp[0][i] = 1;

    int sum = 0, minus = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        for (int j = 1; j <= m; j++) {
            if (j > sum)
                break;
            if (j < a[i])
                continue;;
            for (int k = 0; k <= a[i]; k++) {
                if (j - k < 0)
                    break;
                dp[i][j] += dp[i - 1][j - k] * C(j - k, a[i] - k) % P;
                minus += fac[k] - 1;
                // cout << dp[i - 1][j - k] * C(j - k, a[i] - k) % P << ' ';
            }
            // cout << endl;
            // cout << i << ' ' << j << ':' << dp[i][j] << endl;
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    int times = 0;
    // sum = 0;
    // for (int i = 1; i <= n; i++)
    //     sum += dp[i][m];
    for (int i = 1; i <= n; i++)
        times += (n - a[i]);
    cout << "ans: " << dp[n][m] << ' ' << fac[m] / C(sum, m) << ' ' << minus << endl;;
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

/*
3 3
1 1 2

1 2 3 -> 2
1 3 3 -> 1
*/



// acos(0) = pi