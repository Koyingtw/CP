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


struct Line {
    int a, b;

    Line(): a(-1), b(-1) {}
    Line(int _a, int _b): a(_a), b(_b) {}

    int operator ()(int x) {
        return a * x + b;
    };
};

struct LeeChao {

    struct Node {
        int lch, rch;
        Line li;
        Node(): li(Line()), lch(-1), rch(-1) {}
    };
    vector<Node> arr;

    int newNode() {
        arr.eb(Node());
        return arr.size() - 1;
    }

    void checkNode(int i, char pos) {
        if (pos == 'l') {
            if (arr[i].lch < 0)
                arr[i].lch = newNode();
        }
        else {
            if (arr[i].rch < 0)
                arr[i].rch = newNode();
        }
    }

    void init() {
        newNode();
        newNode();
    }

    void update(int i, int l, int r, Line li) {
        int mid = (l + r) / 2;
        if (l == r) {
            if (li(mid) > arr[i].li(mid)) {
                arr[i].li = li;
                return;
            }
        }

        if (arr[i].li.a > li.a)
            swap(arr[i].li, li);

        if (arr[i].li(mid) > li(mid)) {
            checkNode(i, 'r');
            update(arr[i].rch, mid + 1, r, li);
        }
        else {
            arr[i].li = li;
            checkNode(i, 'l');
            update(arr[i].lch, l, mid, li);
        }
    }

    void insert(int i, int l, int r, int ql, int qr, Line li) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            update(i, l, r, li);
            return;
        }

        int mid = (l + r) / 2;
        if (ql <= mid) {
            checkNode(i, 'l');
            insert(arr[i].lch, l, mid, ql, qr, li);
        }
        if (qr > mid) {
            checkNode(i, 'r');
            insert(arr[i].rch, mid + 1, r, ql, qr, li);
        }
    }

    int query(int i, int l, int r, int pos) {
        if (l == r)
            return arr[i].li(pos);
        
        int mid = (l + r) / 2;
        if (pos <= mid) {
            int qry = INF;
            if (arr[i].lch >= 0)
                qry = query(arr[i].lch, l, mid, pos);
            return min(arr[i].li(pos), qry);
        }
        else {
            int qry = INF;
            if (arr[i].rch >= 0)
                qry = query(arr[i].rch, mid + 1, r, pos);
            return min(arr[i].li(pos), qry);
        }
    }
};

struct SegTree {
    struct Node {
        map<int, LeeChao, greater<int>> LCSeg;    
        map<int, vector<Line>> tag;
        int lch, rch;
        Node(): lch(-1), rch(-1) {}

        void update(int val, Line li) {
            if (val < (*LCSeg.begin()).F) 
                return;
            if (val > (*LCSeg.begin()).F) {
                LCSeg.clear();
                tag.clear();
            }
            if (val >= (*LCSeg.begin()).F) {
                LCSeg[val].update(1, 1, n, li);
                tag[val].eb(li);
            }
        }
    };

    vector<Node> arr;

    int newNode() {
        arr.eb(Node());
        return arr.size() - 1;
    }

    void checkNode(int i, char pos) {
        if (pos == 'l') {
            if (arr[i].lch < 0)
                arr[i].lch = newNode();
        }
        else {
            if (arr[i].rch < 0)
                arr[i].rch = newNode();
        }
    }

    void init() {
        newNode();
        newNode();
    }

    void push(int i, int l, int r) {
        if (l == r)
            return;
        int mid = (l + r) / 2;
        int val = (*arr[i].LCSeg.begin()).F;
        checkNode(i, 'l');
        checkNode(i, 'r');
        for (auto &it: arr[i].tag[val]) {
            arr[arr[i].lch].update(val, it);
            arr[arr[i].rch].update(val, it);
        }
    }

    void update(int i, int l, int r, int ql, int qr, int val, Line li) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            arr[i].update(val, li);
            return;
        }
        
        int mid = (l + r) / 2;
        push(i, l, r);
        if (qr <= mid) {
            checkNode(i, 'l');
            update(arr[i].lch, l, mid, ql, qr, val, li);
        }
        if (ql > mid) {
            checkNode(i, 'r');
            update(arr[i].rch, mid + 1, r, ql, qr, val, li);
        }
    }

    int query(int i, int l, int r, int ql, int qr, int pos) {
        if (l > qr || r < ql)
            return INF;
        push(i, l, r);
        if (ql <= l && r <= qr) {
            return (*arr[i].LCSeg.begin()).S.query(1, 1, n, pos);
        }
        
        checkNode(i, 'l');
        checkNode(i, 'r');
        int mid = (l + r) / 2;
        int q1 = query(arr[i].lch, l, mid, ql, qr, pos);
        int q2 = query(arr[i].rch, mid + 1, r, ql, qr, pos);
        return min(q1, q2);
    }

    
} seg;

int dp[MAXN];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        // x[i] = -x[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> y[i].F >> y[i].S;


    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] >= mx) {
            x[i] = mx;
            seg.update(1, 1, n, 0, i, x[i], Line())
        }


        auto qry = seg.query(1, 0, n, y[i].F, y[i].S, i);
        dp[i] = qry;
        cout << qry << endl;

        
        // seg.update(1, 0, n, i, dp[i]);
    }
    cout << dp[n] << endl;
}

signed main() {
    Koying;
    int t = 1;
    // cin >> t;
    while (t--)
        sol();
}