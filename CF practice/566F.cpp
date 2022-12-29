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
bitset<MAXM> not_prime;
vector<int> p;
int x[MAXM], dp[MAXM];
bitset<MAXM> has;

void make_prime() {
    for (int i = 2; i * i <= MAXM; i++) {
        if (!not_prime[i]) {
            p.pb(i);
            for (int j = i * i; j < MAXM; j += i)
                not_prime[j] = true;
        }
    }
}

void sol() {
    make_prime();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        has[x[i]] = true;
        dp[x[i]] = 1;
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; p[j] * x[i] <= 1e6 && j < p.size(); j++) {
            for (int k = 1; p[j] * x[i] * k <= 1e6; k++) {
                if (has[x[i] * p[j] * k]) {
                    cmax(dp[x[i] * p[j] * k], dp[x[i]] + 1);
                    cmax(ans, dp[x[i] * p[j] * k]);
                    break;
                }
            }
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