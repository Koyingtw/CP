#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int> 
#define all(v) v.begin(), v.end()
#define lowbit(x) (x & (-x))
#define MEM(x, n) memset(x, n, sizeof(x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define cmin(a, b) (a = min(a, b))
#define cmax(a, b) (b = max(a, b))

#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif 
using namespace std;

#define MAXN 405

int n;
int x[MAXN];

void 


void sol() {
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    if (n <= 8 && *max_element(x, x + 8) == 0) {
        dfs(0);
    }
}

signed main() {
    Koying;
    sol();
}