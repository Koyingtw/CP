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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 300005
#define MAXM 1000005 
int n, m;
int cnt[MAXN], dp[MAXN];
bitset<1000005> notPrime;
vector<int> prime;

void make_prime() {
    for (int i = 2; i * i <= n; i++) {
        if (!notPrime[i]) {
            prime.pb(i);
            for (int j = i * i; j <= n; j += i) {
                notPrime[j] = 1;
            }
        }
    }
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

void sol() {
    cin >> n >> m;
    make_prime();
    cnt[1] = m;
    for (int i = 2; i <= n; i++) {
        cnt[i] += m - m / i;
        cout << cnt[i] << ' ';
    }
    cout << endl;

    int tmp = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        tmp *= cnt[i - 1];
        tmp %= P;
        dp[i] = dp[i - 1] + tmp * fpow(cnt[i], n - i + 1);
        dp[i] %= P;
        ans += dp[i];
        ans %= P;
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