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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 105
#define MAXM 1000005 
int n, m;
pii x, y;
int dp[4][MAXN][MAXN];
int fac[MAXN];

void pre() {
    for (int i = 1; i < MAXN; i++)
        fac[i] = fac[i - 1] * i;
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

int C(int a, int b) {   
    if (a < b)
        return 0;
    return fac[a] * fpow(fac[b], P - 2) % P * fpow(fac[a - b], P - 2) % P;
}

void sol() {
    cin >> n >> x.F >> y.F >> x.S >> y.S;
    if (x.S > y.S) {
        swap(x, y);
        x.F = n - x[i].F + 1;
        y.F = n - y[i].F + 1;
    }

    if (x.S < x.F) {
        cout << 0 << endl;
        return;
    }

    int ans = 0;
    dp[0][x.S][0][0] = C(x.S, x.F);
    for (int i = x.F + 1; i <= y.F; i++) {
        for (int j = 0; j <= i - x.S; j++) {
            int k = i - x.S - j;
            dp[1][x.S][j][k] = dp[0][x.S][0][0] * C()
        }
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