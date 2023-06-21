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
        int sum, tag, minus;

        void Add(int l, int r, int val) {
            sum += val * (l + r) * (r - l + 1) / 2;
            tag += val;
        }

        void Minus(int l, int r, int val) {
            sum -= val * (r - l + 1);
            minus += val;
        }
    } arr[MAXN << 2];

    void push(int i, int l, int r) {
        if (l == r || (!arr[i].tag && !arr[i].minus)) {
            arr[i].tag = arr[i].minus = 0;
            return;
        }
        int mid = (l + r) / 2;
        int tag = arr[i].tag;
        int minus = arr[i].minus;
        arr[i].tag = arr[i].minus = 0;
        arr[i * 2].Add(l, mid, tag);
        arr[i * 2 + 1].Add(mid + 1, r, tag);
        arr[i * 2].Minus(l, mid, minus);
        arr[i * 2 + 1].Minus(mid + 1, r, minus);
    }

    void build(int i, int l, int r) {
        arr[i].tag = arr[i].minus = 0;
        if (l == r) {
            arr[i].sum = x[l];
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i].sum = arr[i * 2].sum + arr[i * 2 + 1].sum;
    }

    void update(int i, int l, int r, int ql, int qr, int a, int b) {
        if (ql <= l && r <= qr) {
            arr[i].Add(l, r, a);
            arr[i].Minus(l, r, b);
            return;
        }
        if (ql > r || qr < l)
            return;
        push(i, l, r);
        int mid = (l + r) / 2;
        update(i * 2, l, mid, ql, qr, a, b);
        update(i * 2 + 1, mid + 1, r, ql, qr, a, b);
        arr[i].sum = arr[i * 2].sum + arr[i * 2 + 1].sum;
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return arr[i].sum;
        push(i, l, r);
        int mid = (l + r) >> 1;
        return query(i << 1, l, mid, ql, qr) + query(i << 1 | 1, mid + 1, r, ql, qr);
    }
} seg;

void sol() { 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    seg.build(1, 1, n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            seg.update(1, 1, n, l, r, 1, l - 1);
        }
        else {
            cout << seg.query(1, 1, n, l, r) << endl;
        }
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