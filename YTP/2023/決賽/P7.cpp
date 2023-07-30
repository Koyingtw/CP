#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll __int128_t
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
pair<__int128_t, __int128_t> x[MAXN];

int fac[MAXN];

void pre() {
    for (int)
}

void sol() {
    cin >> n;
    bool ans = 1;
    map<int, int> mp;

    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        x[i].F = a, x[i].S = b;
        // cin >> x[i].F >> x[i].S;
        ans &= (x[i].F == x[i].S);
        mp[x[i].F] = x[i].S;
        // ans &= (x[i].S * min(x[i].F))
    }
    // sort(x, x + n);
    // int mnf = x[0].S;
    // for (int i = 1; i < n; i++) { // x > y
    //     ans &= (x[i].S * mnf == x[i].F * mnf);
    //     cmin(mnf, x[i].S);
    // }
    // mnf = x[n - 1].S;
    // for (int i = n - 2; ~i; i--) { // x < y
    //     ans &= (x[i].S * min(x[i].F, mnf) == x[i].F * x[i].S);
    //     cmin(mnf, x[i].S);
    // }
    // if (n > 1 && ans)
    //     cout << -1 << endl;
    // else
        cout << ans * 100 << endl;
}

// 30 / 10 / 10 / 10 / 10 / 10 / 15 / 20 / 20 / 20 / 20 / 20 / 25 / 25 / 25

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