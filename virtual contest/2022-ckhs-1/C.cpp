#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define MEM(x, n) memset(x, n, sizeof(x))
#define pii pair<int, int>
#if !LOCAL
#pragma GCC optimize("Ofast, unroll-all-loops")
#define endl '\n'
#endif
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
using namespace std;

#define MAXN 1000005
#define MAXM 1000005

int n, q;
int ans[MAXN], mx = 0;
vector<int> fst, mid, lst;

struct Node {
    int lch, rch;
    void init() {
        lch = rch = 0;
    }
} Node[MAXN];

struct Dsu {
    int arr[MAXN], cnt[MAXN];

    void init() {
        for (int i = 1; i <= n; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return 0;
        if (cnt[i] < cnt[j])
            swap(i, j);
        arr[j] = i;
        cnt[i] += arr[j];
        return 1;
    }
} dsu;

void dfs(int i) {
    fst.pb(i);
    if (Node[i].lch) {
        dfs(Node[i].lch);
    }
    mid.pb(i);
    if (Node[i].rch) {
        dfs(Node[i].rch);
    }
    lst.pb(i);
}

void sol() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        Node[i].init();
    dsu.init();

    for (int i = 2, p, t; i <= n; i++) {
        cin >> p >> t;
        if (t == 0)
            Node[p].lch = i;
        else
            Node[p].rch = i;
    }

    dfs(1);

    int cnt = n;

    for (int i = 0; i < n; i++) {
        cnt -= dsu.unite(fst[i], fst[n - i - 1]);
        cnt -= dsu.unite(mid[i], mid[n - i - 1]);
        cnt -= dsu.unite(lst[i], lst[n - i - 1]);
    }

    cmax(mx, cnt);

    int u, v;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        cnt -= dsu.unite(u, v);
        ans[i] = cnt;
        cmax(mx, cnt);
    }
    cout << mx << endl;
    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
}

signed main() {
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--) 
    {
        sol();
    }
    return 0;
}