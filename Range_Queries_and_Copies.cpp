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
vector<int> v;

struct Segment_tree {
    int cur = 0;
    struct Node {
        int lch, rch, sum;

        Node(): lch(0), rch(0), sum(0) {}
    } arr[MAXN * 40];

    void update(int &i, int l, int r, int pos, int val) {
        cur++;
        arr[cur] = arr[i];
        arr[cur].sum += val;
        i = cur;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(arr[i].lch, l, mid, pos, val);
        else
            update(arr[i].rch, mid + 1, r, pos, val);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return arr[i].sum;
        }
        int mid = (l + r) / 2;
        return (ql <= mid ? query(arr[i].lch, l, mid, ql, qr) : 0) + (qr > mid ? query(arr[i].rch, mid + 1, r, ql, qr) : 0);
    }
} seg;

void sol() {
    cin >> n >> m;
    v.pb(0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        seg.update(v[0], 1, n, i, x[i]);
    }
    for (int i = 0; i < m; i++) {
        int op, k, a, b;
        cin >> op >> k;
        if (op == 1 && cin >> a >> b) {
            seg.update(v[k - 1], 1, n, a, b - seg.query(v[k - 1], 1, n, a, a));
        }
        else if (op == 2 && cin >> a >> b) {
            cout << seg.query(v[k - 1], 1, n, a, b) << endl;
        }
        else {
            v.pb(v[k - 1]);
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