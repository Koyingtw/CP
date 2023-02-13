#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define MEM(x, n) memset(x, n, sizeof(x))
#define lowbit(x) (x & (-x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const ll P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

const int MAXN = 200005;
const int MAXM = 1000005;

int n, m;
int x[MAXN];
pii y[MAXN];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    cin >> y[i].F >> y[i].S;

    
}

signed main() {
    Koying;
    int t = 1;
    // cin >> t;
    while (t--)
        sol();
}