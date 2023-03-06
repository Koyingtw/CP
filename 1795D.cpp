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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 300005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int fac[MAXN];

void pre() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % P;
    }
}

int fpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % P;
        }
        a = a * a % P;
        b >>= 1;
    }
    return ans;
}

int C(int a, int b) {
    return fac[a] * fpow(fac[b], P - 2) % P * fpow(fac[a - b], P - 2) % P;
}

void sol() {
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (i % 3 == 0) {
            int tmp = 0;
            int mx = max(x[i] + x[i - 1], max(x[i] + x[i - 2], x[i - 1] + x[i - 2]));
            tmp += (mx == x[i] + x[i - 1]);
            tmp += (mx == x[i] + x[i - 2]);
            tmp += (mx == x[i - 1] + x[i - 2]);
            if (tmp == 2)
                ans = ans * 2 % P;
            else if (tmp == 3)
                ans = ans * 3 % P;
        }
    }
    cout << ans * C(n / 3, n / 6) % P << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    pre();
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}