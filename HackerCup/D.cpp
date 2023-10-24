#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
// #if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
// #endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1000020
#define MAXM 1000005 
int n, m;
int x[MAXN];

bool operator >(pii &a, pii &b) {
    if (a.F != b.F)
        return a.F > b.F;
    else
        return a.S < b.S;
}

bool operator <(pii &a, pii &b) {
    if (a.F != b.F)
        return a.F < b.F;
    else
        return a.S < b.S;
}

struct Node {
    int tag;
    pii mn, mx;
    Node(): mx(pii(-INF, INF)), mn(pii(INF, INF)), tag(0) {}

    void update(int val, int l, int r) {
        if (val % 2) {
            swap(mn, mx);
            mn.F = P - mn.F;
            mx.F = P - mx.F;
        }
        tag += val;
    }
    Node operator +(const Node rhs) {
        Node ret;
        ret.mn = min(mn, rhs.mn);
        ret.mx = max(mx, rhs.mx);
        return ret;
    }
    void operator *=(const Node rhs) {
        mn = rhs.mn;
        mx = rhs.mx;
    }
};

template<typename T>
struct Segment_Tree {
    vector<T> arr;

    void build(int i = 1, int l = 1, int r = n) {
        if (l == r) {
            arr[i].mn = arr[i].mx = pii(x[l], l);
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
        return;
    }

    void init() {
        arr.resize(MAXN << 2, Node()); 
        build();
    }

    void push(int i, int l, int r) {
        if (l == r || arr[i].tag == 0)
            return;
        int mid = (l + r) / 2;
        arr[i * 2].update(arr[i].tag, l, mid);
        arr[i * 2 + 1].update(arr[i].tag, mid + 1, r);
        arr[i].tag = 0;
    }

    void update(int ql, int qr, int val, int i = 1, int l = 1, int r = n) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            arr[i].update(val, l, r);
            return;
        }
        int mid = (l + r) / 2;
        push(i, l, r);
        update(ql, qr, val, i * 2, l, mid);
        update(ql, qr, val, i * 2 + 1, mid + 1, r);
        arr[i] *= arr[i * 2] + arr[i * 2 + 1];
    }

    T query(int ql, int qr, int i = 1, int l = 1, int r = n) {
        if (ql <= l && r <= qr)
            return arr[i];
        if (l > qr || r < ql)
            return T();
        push(i, l, r);
        int mid = (l + r) / 2;
        auto q1 = query(ql, qr, i * 2, l, mid);
        auto q2 = query(ql, qr, i * 2 + 1, mid + 1, r);
        return q1 + q2;
    }
};

Segment_Tree<Node> seg;

void sol(int id) {
    cout << "Case #" << id + 1 << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    seg.init();
    cin >> m;
    int ans = 0;
    int l, r;
    // cout << seg.query(1, 3).mx.S << endl;
    while (m--) {
        cin >> l >> r;
        seg.update(l, r, 1);

        ans += seg.query(1, n).mx.S;
    }
    cout << ans << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	for (int i = 0; i < t; i++) {
            sol(i);
        }
    }
        
    return 0;
}