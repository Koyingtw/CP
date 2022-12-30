#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
#define pii pair<int, int> 
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define pb push_back
#define MEM(x, n) memset(x, n, sizeof(x))
#define lowbit(x) (x & (-x))
#define SZ(x) ((int)x.size())
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
using namespace std;

#define MAXN 100005
#define MAXM 105

int n, m;
int g[MAXN];
int r[MAXM];
int pre[MAXN];

void sol() {
    cin >> n >> m;
    int ans = -INF;

    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        pre[i] = pre[i - 1] + g[i];
    }
    for (int j = 1; j <= m; j++)
        cin >> r[j];

    for (int i = 0; i <= n + m; i++) {
        int l = 
    }
}

signed main() {
    Koying
    sol();
}