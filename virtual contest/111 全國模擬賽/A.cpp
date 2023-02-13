#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9 + 7;

using namespace std;

#define MAXN 300005
int n;
double m;
double w[MAXN];

void sol() {
    double ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w, w + n);
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += w[i];
        ans += (w[i]) / (2 * sum);
    }

    cout << fixed << setprecision(15) << ans * m << endl;
}

signed main() {
    Koying;
    sol();
    return 0;
}