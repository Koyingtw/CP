#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int x[MAXN];

bitset<MAXN> notPrime;
vector<int> prime;
int cnt[MAXN], dp[20][MAXN];
int from[MAXN];
int inlegal = 0;
void make_prime() {
    const int sq = sqrt(MAXN);
    for (int i = 2; i < MAXN; i++) {
        if (!from[i])
            from[i] = i;
        if (!notPrime[i] && i < sq) {
            prime.pb(i);
            for (int j = i * i; j < MAXN; j += i) {
                notPrime[j] = true;
                from[j] = i;
            }
        }
    }
}


void f(int i, int d) {
    while(i > 1) {
        int it = from[i];
        if (cnt[it] > 1)
            inlegal--;
        cnt[it] += d;
        if (cnt[it] > 1)
            inlegal++;
        while (i % it == 0)
            i /= it;
    }
}

// 2 3 6

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1, j = 1; j <= n; j++) {
        f(x[j], 1);
        while (inlegal) {
            f(x[i], -1);
            i++;
        }
        dp[0][j] = i - 1;
    }
    for (int i = 1; i <= __lg(n); i++) 
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];


    int l, r;
    while (m--) {
        cin >> l >> r;
        int ans = 0;
        for (int i = __lg(n); ~i; i--) {
            if (dp[i][r] >= l) {
                ans += (1 << i);
                r = dp[i][r];
                // cout << r << ' ';
            }
        }
        cout << ans + 1 << endl;
    }
}

signed main() {
    Weakoying;
    int t = 1;
    make_prime();
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}