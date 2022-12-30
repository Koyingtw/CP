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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 50005 
int n, m;
bitset<MAXM> not_prime;
vector<int> prime;
int dp[MAXM];

void pre() {
    prime.pb(1);
    int i = 2;
    for (i = 2; i * i < MAXM; i++) {
        if (!not_prime[i]) {
            if (i * i < MAXM) {
                for (int j = i * i; j < MAXM; j += i) {
                    not_prime[j] = 1;
                }
            }
            prime.pb(i);
        }
    }
    // cout << i << endl;
    // return;
    for (; i < MAXM; i++) {
        if (!not_prime[i])
            prime.pb(i);
    }

    MEM(dp, 0x3f);
    dp[0] = 0;

    for (int i = 1; i < MAXM; i++) {
        int mn = 1e9;
        dp[i] = mn;
        for (int j = upper_bound(all(prime), i) - prime.begin() - 1; j >= 0; j--) {
            int it = prime[j];
            if (it > i)
                break;
            if (dp[i - it] % 2 == 0) {
                cmin(dp[i], dp[i - it] + 1);
                // break;
            }
            else
                cmin(mn, dp[i - it] + 1);
            // break;
        }
        if (dp[i] % 2 == 0)
            cmin(dp[i], mn);
    }

    // for (int i = 1; i <= 10; i++)
    //     cout << dp[i] << " " << dp[i] << endl;
}

int x[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        // cout << dp[x[i]] << " " << dp[x[i]] << endl;
    }

    int mn = INF;
    for (int i = 0; i < n; i++) {
        if (!not_prime[x[i]]) {
            cout << "Farmer John" << endl;
            return;
        }
        cmin(mn, dp[x[i]]);
    }
    cout << (mn % 2 == 1 ? "Farmer John" : "Farmer Nhoj") << endl;
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