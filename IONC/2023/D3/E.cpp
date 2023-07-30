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
int n, m, q;

struct Node {
    int sum, tag;
    Node(): sum(0), tag(0) {}

    void update(int val, int l, int r) {
        sum += (val) * (r - l + 1);
        tag += val;
    }
    Node operator +(const Node rhs) {
        Node ret;
        ret.sum = sum + rhs.sum;
        return ret;
    }
    void operator *=(const Node rhs) {
        sum = rhs.sum;
    }
};

template<typename T>
struct Segment_Tree {
    vector<T> arr;

    void init() {
        arr.resize(MAXN << 2, Node()); 
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
        if (ql <= l && r <= qr) {
            arr[i].update(val, l, r);
            return;
        }
        if (l > qr || r < ql)
            return;
        int mid = (l + r) / 2;
        push(i, l, r);
        update(ql, qr, val, i * 2, l, mid);
        update(ql, qr, val, i * 2 + 1, mid + 1, r);
        arr[i].sum = (arr[i * 2] + arr[i * 2 + 1]).sum;
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
array<int, 3> x[MAXN];
vector<array<int, 4>> y(MAXN);
int ans[MAXN];

int version = 0;

void allBS(vector<array<int, 4>> &v, int l, int r, int ql, int qr) {
    if (ql == qr) {
        for (int i = l; i <= r; i++)
            ans[v[i][3]] = ql;
        return;
    }

    int mid = (ql + qr) / 2;

    for (int i = version + 1; i <= mid; i++) {
        // cout << i << endl;
        seg.update(x[i][0], x[i][1], x[i][2]);
    }
    for (int i = version; i > mid; i--) {
        // cout << -i << endl;
        seg.update(x[i][0], x[i][1], -x[i][2]);
    }

    version = mid;

    vector<array<int, 4>> tmp1, tmp2;
    for (int i = l; i <= r; i++) {
        if (seg.query(v[i][0], v[i][1]).sum >= v[i][2])
            tmp1.pb(v[i]);
        else
            tmp2.pb(v[i]);
    }

    for (int i = 0; i < SZ(tmp1); i++) {
        v[i + l] = tmp1[i];
    }

    for (int i = 0; i < SZ(tmp2); i++) {
        v[i + l + SZ(tmp1)] = tmp2[i];
    }


    allBS(v, l, l + SZ(tmp1) - 1, ql, mid);
    allBS(v, l + SZ(tmp1), r, mid + 1, qr);
}

void sol() {
    cin >> n >> m >> q;
    seg.init();

    for (int i = 1; i <= m; i++) {
        cin >> x[i][0] >> x[i][1] >> x[i][2];
        // seg.update(x[i][0], x[i][1], x[i][2]);
    }
    for (int i = 0; i < q; i++) {
        cin >> y[i][0] >> y[i][1] >> y[i][2];
        y[i][3] = i;
    }
    allBS(y, 0, q - 1, 1, m + 1);

    for (int i = 0; i < q; i++)
        cout << (ans[i] <= m ? ans[i] : -1) << endl;
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