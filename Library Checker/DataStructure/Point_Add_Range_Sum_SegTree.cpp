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
        T val;

        Node (): val(0) {} // mx: -INF, mn: INF, sum: 0, gcd: 1, lcm: 1

        Node operator +(const Node &rhs) {
            Node ret;
            // sum:
            ret.val = val + rhs.val;
            // mx:
            // ret.val = max(val, rhs.val);
            // mn:
            // ret.val = min(val, rhs.val);
            // gcd:
            // ret.val = __gcd(val, rhs.val);
            // lcm:
            // ret.val = val / __gcd(val, rhs.val) * rhs.val;
            return ret;
        }

        void update(int val) {
            // sum:
            this->val += val;
            // mx:
            // this->val = val;
            // mn:
            // this->val = val;
            // gcd:
            // this->val = val;
            // lcm:
            // this->val = val;
        }
    };

    vector<Node> arr;

    Segment_Tree() {
        arr.resize(RANGE << 2);
    }

    void build(vector<int> &v, int i = 1, int l = 1, int r = n) {
        if (l == r) {
            arr[i].val = v[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(v, i << 1, l, mid);
        build(v, i << 1 | 1, mid + 1, r);
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }

    void update(int pos, int val, int i = 1, int l = 1, int r = n) {
        if (l == r) {
            arr[i].update(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(pos, val, i << 1, l, mid);
        } else {
            update(pos, val, i << 1 | 1, mid + 1, r);
        }
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }

    Node query(int ql, int qr, int i = 1, int l = 1, int r = n) {
        if (l > qr || r < ql) {
            return Node();
        }
        if (ql <= l && r <= qr) {
            return arr[i];
        }
        int mid = (l + r) >> 1;
        return query(ql, qr, i << 1, l, mid) + query(ql, qr, i << 1 | 1, mid + 1, r);
    }
};

Segment_Tree<int, 500000> seg;
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
        if (op == 0)
            seg.update(a + 1, b);
        else 
            cout << seg.query(a + 1, b).val << endl;
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