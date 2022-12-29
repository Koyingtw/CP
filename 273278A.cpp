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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Seg_Tree {
    struct Node {
        int pre, suf, sum, ans;

        Node(): pre(-INF), suf(-INF), sum(0), ans(-INF){}
        Node(int _val): 
            pre(_val), suf(_val), sum(_val), ans(max(_val, 0)){}

        Node operator +(Node _a) {
            Node res = Node();
            cmax(res.pre, max(pre, sum + _a.pre));
            cmax(res.suf, max(_a.suf, suf + _a.sum));
            res.sum = sum + _a.sum;
            cmax(res.ans, max(res.pre, res.suf));
            cmax(res.ans, max(ans, _a.ans));
            cmax(res.ans, suf + _a.pre);
            return res;
        }
    } arr[MAXN << 2];

    void build(int i, int l, int r) {
        if (l == r) {
            arr[i] = Node(x[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int i, int l, int r, int pos, int val) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            arr[i] = Node(val);
            return;
        }
        int mid = (l + r) / 2;
        update(i * 2, l, mid, pos, val);
        update(i * 2 + 1, mid + 1, r, pos, val);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    Node query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return Node(0);
        if (ql <= l && r <= qr)
            return arr[i];
        int mid = (l + r) / 2;
        return query(i * 2, l, mid, ql, qr) + query(i * 2 + 1, mid + 1, r, ql, qr);
    }
} Seg;

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    Seg.build(1, 1, n);
    // for (int i = 1; i <= 8; i++)
    //     cout << Seg.arr[i].sum << endl;
    // return;

    cout << Seg.query(1, 1, n, 1, n).ans << endl;
    while (m--) {
        int pos, val;
        cin >> pos >> val;
        pos++;
        Seg.update(1, 1, n, pos, val);
        cout << Seg.query(1, 1, n, 1, n).ans << endl;
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