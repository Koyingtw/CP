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

template<typename T, int RANGE>
struct Segment_Tree {
    struct Node {
        int sum, pre, mx;

        Node() {
            sum = 0;
            pre = 0;
            mx = 0;
        }

        Node operator +(const Node &rhs) {
            Node ret;
            ret.sum = sum + rhs.sum;
            ret.pre = max(pre, sum + rhs.pre);
            // seg[id].mx = max(seg[id * 2].suf + seg[id * 2 + 1].pre, max(seg[id * 2].mx, seg[id * 2 + 1].mx));
            return ret;
        }
    };
    vector<Node> arr;

    Segment_Tree() {
        arr.resize(RANGE << 2);
    }

    void build(vector<int> &v, int i = 1, int l = 1, int r = n) {
        if (l == r) {
            arr[i].sum = v[l];
            arr[i].pre = max(v[l], 0);
            arr[i].mx = max(v[l], 0);
            return;
        }
        int mid = (l + r) / 2;
        build(v, i * 2, l, mid);
        build(v, i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int pos, int val, int i = 1, int l = 1, int r = n) {
        if (l == r) {
            arr[i].sum = val;
            arr[i].pre = max(val, 0);
            arr[i].mx = max(val, 0);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(pos, val, i * 2, l, mid);
        else
            update(pos, val, i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    Node query(int ql, int qr, int i = 1, int l = 1, int r = n) {
        if (ql <= l && r <= qr)
            return arr[i];
        if (ql > r || qr < l)
            return Node();
        int mid = (l + r) / 2;
        return query(ql, qr, i * 2, l, mid) + query(ql, qr, i * 2 + 1, mid + 1, r);
    }
};

Segment_Tree<int, MAXN> seg;
vector<int> v;

void sol() {
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    seg.build(v);

    int op, a, b;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 1)
            seg.update(a, b);
        else
            cout << seg.query(a, b).pre << endl;
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