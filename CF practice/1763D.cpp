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
#define MAXN 105
#define MAXM 1000005 
int n, m;
int fac[MAXN];

void pre() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= P;
    }
}

int fpow(int a, int b) {
    if (b < 0)
        return 0;
    int res = 1;
    while (b) {
        if (b % 2) {
            res *= a;
            res %= P;
        }
        a *= a;
        a %= P;
        b /= 2;
    }
    return res;
}

int C(int a, int b) {
    if (a < b || a < 0 || b < 0)   
        return 0;
    return (fac[a] * fpow(fac[b], P - 2)) % P * fpow(fac[a - b], P - 2) % P;
}

void sol() {
    int i, j, x, y;
    cin >> n >> i >> j >> x >> y;
    if (x > y) {
        swap(x, y);
        i = n - i + 1;
        j = n - j + 1;
        swap(i, j);
    }

    int ans = 0;
    bool legal = false;
    if (y == n) {        
        int tmp = (j != n) * C(x - 1, i - 1) * C(n - x - 1, j - i - 1) % P;
        ans += tmp;
    }
    else {
        // case 1
        ans += (C(x - 1, i - 1) * C(y - x - 1, n - j - (x - i))) % P * fpow(2, j - i - 2) % P * C(n - y - 1 - (j - i - 2), 0) % P;
        ans += (C(x - 1, i - 1) * C(y - x - 1, j - i - 1)) % P * fpow(2, n - j - 2) % P * C(n - y - 1 - (n - j - 2), 0) % P;
        cout << ans << ' ';
        ans = 0;
        for (int k = i + 1; k < j; k++) {
            legal = true;
            int a = (n - y - 1) - (j - k - 1);
            int tmp = 1;
            tmp *= (C(x - 1, i - 1) * C(y - x - 1, n - j - (x - i))) % P * C(n - y - 1, (j - k - 1)) % P;
            // cout << j - k - 1 << ' ';
            tmp %= P;
            // tmp *= tmp;
            tmp %= P;
            ans += tmp;
            ans %= P;
        }
        // cout << ans << ' ' << j - i - 2 << ' ' << (fpow(2, min(j - i - 2, n - y - 1)) % P) * C(n - y - 1 - min(j - i - 2, n - y - 1), 0) % P << endl;
        
        // case 2
        for (int k = j + 1; k < n; k++) {
            legal = true;
            int tmp = (C(x - 1, i - 1) * C(y - x - 1, j - i - 1)) % P * C(n - y - 1, k - j - 1) % P;
            tmp %= P;
            tmp %= P;
            ans += tmp;
            ans %= P;
        }
    }
    cout << ans % P << endl;
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