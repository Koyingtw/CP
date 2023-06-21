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
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Segment_Tree {
    struct Node {
        int sum, inc, st;

        Node (): sum(0), inc(0), st(0) {}
        Node (int val): sum(val), inc(0), st(0) {}
    } arr[MAXN << 2];

    void push(int i, int l, int r) {
        if (l == r) {
            arr[i].st = arr[i].inc = 0;
            return;
        }
        if (arr[i].st) {
            set(i * 2, l, (l + r) / 2, arr[i].st);
            set(i * 2 + 1, (l + r) / 2 + 1, r, arr[i].st);
            arr[i].st = 0;
        }
        if (arr[i].inc) {
            inc(i * 2, l, (l + r) / 2, arr[i].inc);
            inc(i * 2 + 1, (l + r) / 2 + 1, r, arr[i].inc);
            arr[i].inc = 0;
        }
    }


    void inc(int i, int l, int r, int val) {
        arr[i].sum += (r - l + 1) * val;
        arr[i].inc += val;
    }

    void set(int i, int l, int r, int val) {
        arr[i].sum = (r - l + 1) * val;
        arr[i].st = val;
        arr[i].inc = 0;
    }

    void build(int i, int l, int r) {
        if (l == r) {
            arr[i] = Node(x[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        arr[i] = Node(arr[i << 1].sum + arr[i << 1 | 1].sum);
    }

    void update_set(int i, int l, int r, int ql, int qr, int val) {
        push(i, l, r);
        if (ql <= l && r <= qr) {
            set(i, l, r, val);
            return;
        }
        if (ql > r || l > qr)
            return;
        int mid = (l + r) >> 1;
        update_set(i << 1, l, mid, ql, qr, val);
        update_set(i << 1 | 1, mid + 1, r, ql, qr, val);
        arr[i] = Node(arr[i << 1].sum + arr[i << 1 | 1].sum);
    }

    void update_inc(int i, int l, int r, int ql, int qr, int val) {
        push(i, l, r);
        if (ql <= l && r <= qr) {
            inc(i, l, r, val);
            return;
        }
        if (ql > r || l > qr)
            return;
        int mid = (l + r) >> 1;
        update_inc(i << 1, l, mid, ql, qr, val);
        update_inc(i << 1 | 1, mid + 1, r, ql, qr, val);
        arr[i] = Node(arr[i << 1].sum + arr[i << 1 | 1].sum);
    }

    int query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (ql > r || l > qr)
            return 0;
        if (ql <= l && r <= qr)
            return arr[i].sum;
        int mid = (l + r) >> 1;
        // push_inc(i, l, r);
        return query(i << 1, l, mid, ql, qr) + query(i << 1 | 1, mid + 1, r, ql, qr);
    }
} Seg;

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    Seg.build(1, 1, n);
    while (m--) {
        int op, l, r, val;
        cin >> op >> l >> r;
        if (op == 1 && cin >> val)
            Seg.update_inc(1, 1, n, l, r, val);
        else if (op == 2 && cin >> val)
            Seg.update_set(1, 1, n, l, r, val);
        else
            cout << Seg.query(1, 1, n, l, r) << endl;
    }
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}