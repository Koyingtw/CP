#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
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
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Segment_Tree {
    struct Node {
        int mx, tag;

        void update(int val) {
            tag += val;
            mx += val;
        }

        Node operator +(Node _a) {
            cmax(_a.mx, mx);
            return _a;
        }

        Node() {
            mx = 0;
            tag = 0;
        }
    };
    Node arr[MAXN << 2];

    void push(int i, int l, int r) {
        int tag = arr[i].tag;
        arr[i].tag = 0;
        if (l == r)
            return;

        arr[i * 2].update(tag);
        arr[i * 2 + 1].update(tag);
    }

    void build(int i, int l, int r) {
        arr[i] = Node();
        if (l == r)
            return;
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
    }

    void update(int i, int l, int r, int ql, int qr, int val) { 
        if (ql > r || qr < l)
            return;
        if (ql <= l && r <= qr) {
            arr[i].update(val);
            return;
        }

        int mid = (l + r) / 2;
        push(i, l, r);
        update(i * 2, l, mid, ql, qr, val);
        update(i * 2 + 1, mid + 1, r, ql, qr, val);
        arr[i].mx = (arr[i * 2] + arr[i * 2 + 1]).mx;
    }

    Node query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (ql > r || qr < l) 
            return Node();
        if (ql <= l && r <= qr)
            return arr[i];
        
        int mid = (l + r) / 2;
        push(i, l, r);
        return query(i * 2, l, mid, ql, qr) + query(i * 2 + 1, mid + 1, r, ql, qr);
    }
} seg;

void sol() {
    cin >> n;
    seg.build(1, 1, n);
    int l = 1, r = 0;
    for (int i = 0, k, q; i < n; i++) {
        cin >> k >> q;
        if (k == 1) {
            seg.update(1, 1, n, l, r, q);
        }
        if (k == 2) {
            // cout << seg.query(1, 1, n, 2, 3).mx << endl;
            for (int i = l; i <= r && q > 0; i++) {
                l = i;
                int tmp = min(q, x[l]);
                x[l] -= tmp;
                q -= tmp;
                // seg.update(1, 1, n, l, l, -INF);
                if (x[l] <= 0)
                    l = i + 1;
            }
        }
        if (k == 3) {
            r++;
            x[r] = q;
        }

        cout << seg.query(1, 1, n, l, r).mx << endl;
        // cout << seg.arr[9].mx << endl;
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