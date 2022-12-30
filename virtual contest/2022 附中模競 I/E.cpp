#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lowbit(x) (x & (-x))
#define int long long
#define pii pair<int, int>
#define MEM(x, n) memset(x, n, sizeof(x))
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define cmax(a, b) a = max(a, b)
#define all(v) v.begin(), v.end()
#if !LOCAL
#define endl '\n'
#pragma optimize("Ofast, unroll-all-loops")
#endif

using namespace std;

#define MAXN 200005
#define MAXM 1000005

int n, m;
int h[MAXN], v[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];
    void init() {
        for (int i = 0; i < MAXN; i++)
            arr[i] = 0;
    }

    void update(int i, int val) {
        for (; i < MAXN; i += lowbit(i)) {
            cmax(arr[i], val);
        }
    }

    int query(int i) {
        int res = 0;
        for (; i; i -= lowbit(i)) {
            cmax(res, arr[i]);
        }
        return res;
    }
} BIT1, BIT2;
// BIT1: low point
// BIT2: high point


void sol() {
    cin >> n;
    vector<int> vv;

    BIT1.init();
    BIT2.init();

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> v[i];
        vv.push_back(h[i]);
    }
    sort(all(vv));
    vv.erase(unique(all(vv)), vv.end());

    for (int i = 0; i < n; i++)
        h[i] = upper_bound(all(vv), h[i]) - vv.begin();


    for (int i = 0; i < n; i++) {
        int qq1 = BIT1.query(h[i] - 1);
        int qq2 = BIT2.query(vv.size() - h[i]);
        BIT2.update(vv.size() - h[i] + 1, qq1 + v[i]);
        BIT1.update(h[i], qq2 + v[i]);
    }

    cout << max(BIT1.query(n), BIT2.query(n)) << endl;
}

signed main() {
    Koying
    int _ = 1;
    // cin >> _
    while (_--) {
        sol();
    }

    return 0;
}