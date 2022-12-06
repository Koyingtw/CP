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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> in, x, y;

struct Segment_Tree {
    int arr[MAXN << 2];

    void build(int i, int l, int r, vector<int> &a) {
        if (l == r) {
            arr[i] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(i * 2, l, mid, a);
        build(i * 2 + 1, mid + 1, r, a);

        arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
    }

    void update(int i, int l, int r, int pos, int val) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            arr[i] = val;
            return;
        }

        int mid = (l + r) / 2;
        update(i * 2, l, mid, pos, val);
        update(i * 2 + 1, mid + 1, r, pos, val);

        arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return INF;
        if (ql <= l && r <= qr) {
            return arr[i];
        }
        
        int mid = (l + r) / 2;
        int q1 = query(i * 2, l, mid, ql, qr);
        int q2 = query(i * 2 + 1, mid + 1, r, ql, qr);
        return min(q1, q2);
    }
} Seg1, Seg2;

void sol() {
    cin >> n >> m;
    in.resize(n + 1);
    x.resize(n + 1);
    y.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        y[i] = x[i] = in[i];
        x[i] += i;
        y[i] += (n - i + 1);
    }

    Seg1.build(1, 1, n, x);
    Seg2.build(1, 1, n, y);

    int op, k, val;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> k >> val;
            x[k] = val + k;
            y[k] = val + (n - k + 1);

            Seg1.update(1, 1, n, k, x[k]);
            Seg2.update(1, 1, n, k, y[k]);
        }
        else {
            cin >> k;
            int q1 = Seg1.query(1, 1, n, k, n);
            int q2 = Seg2.query(1, 1, n, 1, k - 1);

            cout << min(q1 - k, q2 - (n - k + 1)) << endl;
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