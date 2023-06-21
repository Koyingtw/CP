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
int x[MAXN], pre[MAXN];
vector<pii> Q[MAXN];

struct Setment_Tree {
    struct Node {
        int sum, tag;

        void update(int l, int r, int val) {
            sum = (r - l + 1) * val;
            tag = val;
        }
    } arr[MAXN << 2];

    void push(int i, int l, int r) {
        if (l == r || !arr[i].tag)
            return;
        int mid = (l + r) / 2, tag = arr[i].tag;
        arr[i * 2].update(l, mid, tag);
        arr[i * 2 + 1].update(mid + 1, r, tag);
        arr[i].tag = 0;
    }

    void build(int i, int l, int r) {
        if (l == r) {
            arr[i].sum = x[l];
            arr[i].tag = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i].sum = arr[i * 2].sum + arr[i * 2 + 1].sum;
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            arr[i].update(l, r, val);
            return;
        }
        if (ql > r || qr < l)
            return;

        push(i, l, r);
        int mid = (l + r) / 2;
        update(i * 2, l, mid, ql, qr, val);
        update(i * 2 + 1, mid + 1, r, ql, qr, val);
        arr[i].sum = arr[i * 2].sum + arr[i * 2 + 1].sum;
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return arr[i].sum;
        if (ql > r || qr < l)
            return 0;
        
        push(i, l, r);
        int mid = (l + r) / 2;
        return query(i * 2, l, mid, ql, qr) + query(i * 2 + 1, mid + 1, r, ql, qr);
    }
} Seg;

int ans[MAXN];

void sol() {    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
    }

    Seg.build(1, 1, n);

    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        Q[l].push_back({r, i});
    }

    stack<pii> st;
    st.push({INFLL, n + 1});
    for (int i = n; i > 0; i--) {
        while (st.size() && st.top().F < x[i]) {
            st.pop();
        }

        if (st.size()) {
            Seg.update(1, 1, n, i, st.top().S - 1, x[i]);
        }
        
        for (auto &it: Q[i]) {
            ans[it.S] = Seg.query(1, 1, n, i, it.F) - (pre[it.F] - pre[i - 1]);
        }

        st.push({x[i], i});
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
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