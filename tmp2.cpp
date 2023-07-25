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
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 15
#define MAXM 1005
int n, m;
int x[MAXN];
bitset<MAXM> dp[MAXM];

void sol() {
    for (int i = 0; i < MAXM; i++)
        dp[i].reset();
    cin >> n;
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        for (int j = MAXM - 1; j >= 0; j--) {
            for (int k = MAXM - 1; k >= 0; k--) if (dp[j][k]) {
                for (int l = 0; l <= x[i] / 10; l++) {
                    if (j + l < MAXM && k + (x[i] - l * 10) / 7 < MAXM) {
                        dp[j + l][k + (x[i] - l * 10) / 7] = true;
                        cmax(ans, min((j + l) / 2, k + (x[i] - l * 10) / 7));
                        // if (ans == 9)
                        // cout << j + l << " " << k + (x[i] - l * 10) / 7 << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    Weakoying;
    int t = 2;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}