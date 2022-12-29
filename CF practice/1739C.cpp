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
#define MAXN 70
#define MAXM 1000005 
int n, m;
int fac[MAXN];

void pre() {
    fac[0] = 1;
    // p[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = (fac[i - 1] * i) % P;
}

int fpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % P;
        a = (a * a) % P;
        b >>= 1;
    }
    return ans;
}

int C(int a, int b) {
    return (fac[a] * fpow(fac[b], P - 2)) % P * fpow(fac[a - b], P - 2) % P;
}


void sol() {
    cin >> n;
    int ans[3];
    ans[0] = ans[1] = ans[2] = 0;

    ans[0] += C(n - 1, n / 2 - 1);

    for (int i = 3; i <= n / 2; i += 2) {
        ans[0] += C(n - i * 2 + 2, n / 2 - i);
        ans[0] += C(n - i * 2 + 1, n / 2 - i);
        ans[0] %= P;
    }

    ans[1] = C(n, n / 2) - ans[0] - 1;
    ans[1] = (ans[1] % P + P) % P;

    cout << ans[0] % P << ' ' << ans[1] << ' ' << 1 << endl;
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