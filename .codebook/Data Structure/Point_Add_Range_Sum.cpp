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
vector<int> v(MAXN);

struct Sum_seg {
    struct Node {
        int sum, tag;

        Node operator +(const Node &_a) {
            Node res;
            res.sum = sum + _a.sum;
            res.tag = 0;
            return res;
        }

        void update(int l, int r, int val) {
            sum += (r - l + 1) * val;
            tag += val;
        }
    } arr[MAXN << 2];

    void push(int i, int l, int r) {
        if (l == r)
            return;
        int tag = arr[i].tag;
        int mid = (l + r) >> 1;
        arr[i << 1].update(l, mid, tag);
        arr[i << 1 | 1].update(mid + 1, r, tag);
        arr[i].tag = 0;
    }

    void build(vector<int> &v, int i, int l, int r) {
        if (l == r) {
            arr[i] = {v[l], 0};
            return;
        }
        int mid = (l + r) >> 1;
        build(v, i << 1, l, mid);
        build(v, i << 1 | 1, mid + 1, r);
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql) return;
        if (ql <= l && r <= qr) {
            arr[i].update(l, r, val);
            return;
        }

        int mid = (l + r) >> 1;
        push(i, l, r);
        update(i << 1, l, mid, ql, qr, val);
        update(i << 1 | 1, mid + 1, r, ql, qr, val);
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }

    Node query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return {0, 0};
        if (ql <= l && r <= qr) return arr[i];
        push(i, l, r);
        int mid = (l + r) >> 1;
        return query(i << 1, l, mid, ql, qr) + query(i << 1 | 1, mid + 1, r, ql, qr);
    }
} seg;

void sol() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    seg.build(v, 1, 1, n);

    while (m--) {
        int op, l, r, val;
        cin >> op;
        if (op == 0) {
            cin >> l >> val;
            seg.update(1, 1, n, l + 1, l + 1, val);
        }
        else {
            cin >> l >> r;
            cout << seg.query(1, 1, n, l + 1, r).sum << endl;
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