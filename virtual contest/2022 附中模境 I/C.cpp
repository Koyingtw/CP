#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define MEM(x, n) memset(x, n, sizeof(x))
#define F first
#define S second
#define all(v) v.begin(), v.end()
#if !LOCAL
#define endl '\n'
#pragma optimize("Ofast, unroll-all-loops")
#endif

using namespace std;

#define MAXN 200005
#define MAXM 1000005

int n, m, k;
vector<pii> G[MAXN];

void sol() {
    cin >> n >> m >> k;
    for (int i, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
}

signed main() {
    int _ = 1;
    // cin >> _
    while (_--) {

    }

    return 0;
}