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
#define MAXN 40005
#define MAXM 1000005 
int n, m, c;
int x[MAXN];
bitset<MAXN> dp[2][4001];


void sol() {
	cin >> n >> m >> c;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        for (int j = 0; j < c; j++) {
            dp[(i + 1) % 2][(j + x[i]) % c] |= (dp[i % 2][j] << 1);
            dp[i % 2][j].reset();
        }
    }
    for (int i = c - 1; i >= 0; i--) {
        if (dp[n % 2][i][m]) {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
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