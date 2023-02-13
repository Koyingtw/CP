#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
const ll INFLl = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 

int n, m, q;

struct SegTree {
    ll arr[MAXN << 2], tag[MAXN << 2];

    void init() {
        MEM(arr, 0);
        MEM(tag, 0);
    }

    void push(int i, int l, int r) {
        if (l == r) {
            tag[i] = 0;
            return;
        }
        int mid = (l + r) / 2;
        arr[i * 2] += tag[i];
        tag[i * 2] += tag[i];
        arr[i * 2 + 1] += tag[i];
        tag[i * 2 + 1] += tag[i];
        tag[i] = 0;
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            arr[i] += val;
            tag[i] += val;
            return;
        }
        int mid = (l + r) / 2;
        push(i, l, r);
        update(i * 2, l, mid, ql, qr, val);
        update(i * 2 + 1, mid + 1, r, ql, qr, val);
        arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
    }

    ll query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (l > qr || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return arr[i];
        int mid = (l + r) / 2;
        int q1 = query(i * 2, l, mid, ql, qr), q2 = query(i * 2 + 1, mid + 1, r, ql, qr);
        return max(q1, q2);
    }
} seg;

struct Data {
    int l, r, k;
} x[MAXN];

struct Event {
    int l, r, v;
} y[MAXN];

int ans[MAXN];

void DC(int l, int r, vector<int> &qry) {
    int mid = (l + r) / 2;
    for (int i = l; i <= mid; i++)
        seg.update(1, 1, n, y[i].l, y[i].r, y[i].v);

    if (l == r) {
        for (auto &it: qry) if (seg.query(1, 1, n, x[it].l, x[it].r) >= x[it].k)
            ans[it] = l;
        for (int i = l; i <= mid; i++)
            seg.update(1, 1, n, y[i].l, y[i].r, -y[i].v);    
        return;
    }

    vector<int> lqry, rqry;
    for (auto &it: qry) {
        // cout << it << ": " << seg.query(1, 1, n, x[it].l, x[it].r) << ' ';
        if (seg.query(1, 1, n, x[it].l, x[it].r) >= x[it].k)
            lqry.push_back(it);
        else
            rqry.push_back(it);
    }


    DC(mid + 1, r, rqry);
    for (int i = l; i <= mid; i++)
        seg.update(1, 1, n, y[i].l, y[i].r, -y[i].v);
    DC(l, mid, lqry);
    vector<int> ().swap(qry);
}

void sol() {
    cin >> n >> m >> q;
    seg.init();
    for (int i = 0; i < m; i++)
        cin >> x[i].l >> x[i].r >> x[i].k;
    for (int j = 0; j < q; j++)
        cin >> y[j].l >> y[j].r >> y[j].v;

    MEM(ans, -1);
    vector<int> qry;
    for (int i = 0; i < m; i++)
        qry.push_back(i);

    DC(0, q - 1, qry);

    for (int i = 0; i < m; i++)
        cout << (ans[i] < 0 ? -1: ans[i] + 1) << " \n"[i == m - 1];
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