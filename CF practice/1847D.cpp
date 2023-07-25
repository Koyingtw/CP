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
string s;
pii x[MAXN];
int pos[MAXN];
vector<int> G[MAXN];

struct Min_Segment_Tree {
    int arr[MAXN << 3]; 
    int tag[MAXN << 3];

    void push_up(int i) {
        arr[i] = min(arr[i << 1], arr[i << 1 | 1]);
    }

    void push_down(int i) {
        if (tag[i] < INF) {
            cmin(arr[i << 1], tag[i]);
            cmin(arr[i << 1 | 1], tag[i]);
            cmin(tag[i << 1], tag[i]);
            cmin(tag[i << 1 | 1], tag[i]);
            tag[i] = INF;
        }
    }

    void build(int i, int l, int r) {
        tag[i] = INF;
        arr[i] = INF;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            cmin(arr[i], val);
            tag[i] = val;
            return;
        }
        push_down(i);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(i << 1, l, mid, ql, qr, val);
        if (qr > mid)
            update(i << 1 | 1, mid + 1, r, ql, qr, val);
        push_up(i);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return arr[i];
        push_down(i);
        int mid = (l + r) >> 1;
        int ans = INF;
        if (ql <= mid)
            cmin(ans, query(i << 1, l, mid, ql, qr));
        if (qr > mid)
            cmin(ans, query(i << 1 | 1, mid + 1, r, ql, qr));
        return ans;
    }
} seg;

struct Fenwick_Tree {
    int arr[MAXN];

    void init() {
        for (int i = 1; i <= n; i++)
            arr[i] = 0;
    }

    void update(int i, int val) {
        while (i <= n) {
            arr[i] += val;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int ans = 0;
        while (i) {
            ans += arr[i];
            i -= lowbit(i);
        }
        return ans;
    }
} BIT;

void sol() {
    cin >> n >> m >> q;
    cin >> s;
    s = " " + s;
    seg.build(1, 1, n);
    vector<pii> v;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        seg.update(1, 1, n, a, b, i);
        G[a].pb(i);
        G[b + 1].pb(-i);
    }
    sort(all(v));
    

    int cnt = 0, cnt2 = 0, ans = 0;
    set<int> st;
    st.insert(INF);
    for (int i = 1; i <= n; i++) {
        for (auto it: G[i]) {
            if (it > 0)
                st.insert(it);
            else
                st.erase(-it);
        }
        x[i] = {(*st.begin()), i};
        if (s[i] == '1')
            cnt++;
        cnt2 += (x[i].F <= m);
    }

    sort(x + 1, x + n + 1);

    for (int i = 1; i <= n; i++) {
        pos[x[i].S] = i;
        BIT.update(i, s[x[i].S] - '0');
    }

    for (int i = 0, a; i < q; i++) {
        cin >> a;

        if (s[a] == '0') {
            cnt++;
            BIT.update(pos[a], 1);
            s[a] = '1';
        }
        else {
            cnt--;
            BIT.update(pos[a], -1);
            s[a] = '0';
        }

        cout << min(cnt, cnt2) - BIT.query(min(cnt, cnt2)) << endl;
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