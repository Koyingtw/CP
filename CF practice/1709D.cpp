#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m, q;
int h[MAXN];

struct setment_tree {
    struct Node {
        int l, r, mx;
        void operator = (Node a){
            mx = a.mx;
        }

        Node operator + (Node a) {
            Node res;
            res.mx = max(mx, a.mx);
            return res;
        }
    };

    Node tree[MAXM << 2];

    void build(int i, int l, int r) {
        tree[i].l = l;
        tree[i].r = r;
        tree[i].mx = INF;
        if (l == r) {
            tree[i].mx = h[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    int query(int i, int ql, int qr) {
        int l = tree[i].l, r = tree[i].r;
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) {
            return tree[i].mx;
        }
        return max(query(i << 1, ql, qr), query(i << 1 | 1, ql, qr));
    }
} seg;

struct Max_Sparse_Table {
    int ST[20][MAXN];

    void build() {
        for (int i = 1; i <= m; i++)
            ST[0][i] = h[i];
        for (int i = 1; i <= __lg(m); i++) {
            for (int j = 1; j <= m; j++) {
                ST[i][j] = max(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k = __lg(r - l + 1);
        return max(ST[k][l], ST[k][r - (1 << k) + 1]);
    }
} ST;

void sol() {
	cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> h[i];
    // seg.build(1, 1, m);
    ST.build();

    cin >> q;
    while (q--) {
        int x1, x2, y1, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        bool legal = true;
        legal &= (abs(x1 - x2) % k == 0);
        legal &= (abs(y1 - y2) % k == 0);
        legal &= (h[y1] < x1);
        legal &= (h[y2] < x2);
        legal &= (ST.query(min(y1, y2), max(y1, y2)) < (x1 + k * ((n - x1) / k)));

        cout << (legal ? "YES" : "NO") << endl;
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