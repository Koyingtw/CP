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
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
using namespace std;

#define MAXN 200005

int n, m;
int sz[MAXN], d[MAXN];
vector<int> G[MAXN];
pii ans[MAXN];

int dfs(int i, int dep) {
    cmax(ans[dep].S, i);
    d[i] = dep;
    for (int e: G[i]) {
        sz[i] += dfs(e, dep + 1) + 1;
    }
    return sz[i];
}

struct Setment_Tree {
    struct Node {
        int mx, tag;

        Node(): mx(0), tag(-1) {}

        void update(int val) {
            if (mx < val) {
                mx = val;
                tag = val;
            }
        }
    } arr[MAXN << 2];

    void push(int i) {
        if (arr[i].tag == -1)
            return;
        arr[i * 2].update(arr[i].tag);
        arr[i * 2 + 1].update(arr[i].tag);
        arr[i].tag = -1;
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            arr[i].update(val);
            return;
        }
        int mid = (l + r) / 2;
        push(i);
        update(i * 2, l, mid, ql, qr, val);
        update(i * 2 + 1, mid + 1, r, ql, qr, val);
        arr[i].mx = max(arr[i * 2].mx, arr[i * 2 + 1].mx);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return -INF;
        if (ql <= l && r <= qr) {
            return arr[i].mx;
        }
        push(i);
        int mid = (l + r) / 2;
        int q1 = query(i * 2, l, mid, ql, qr), q2 = query(i * 2 + 1, mid + 1, r, ql, qr);
        return max(q1, q2);
    }
} Seg;

void sol() {
    cin >> n;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a;
        while (a--) {
            cin >> b;
            G[i].pb(b);
        }
    }

    dfs(1, 1);

    for (int i = 1; i <= n; i++) {
        if (ans[i].S == 0)
            ans[i].S = ans[i - 1].S;
        Seg.update(1, 1, n, d[i], n - sz[i], i);
    }

    for (int i = 1, now = 1; i <= n && now <= n; i++) {
        while (n - sz[now] < i) {
            now++;
        }
        ans[i].F = now;
        cout << ans[i].F << ' ' << Seg.query(1, 1, n, i, i) << endl;
    }

    
}

signed main() {
    Koying
    sol();
}