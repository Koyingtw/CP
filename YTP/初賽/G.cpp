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
int n, m;

struct segment_tree {
    struct Node
    {
        int l, r, tag, sum;
        void update(int val){sum = (r - l + 1) * val, tag = val;}
    }seg[4 * MAXN];
    void pull(int id)
    {
        seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
    }
    void push(int id)
    {
        int tag = seg[id].tag;
        seg[id * 2].update(tag);
        seg[id * 2 + 1].update(tag);
        seg[id].tag = 0;
    }
    void build(int id, int l, int r)
    {
        seg[id].l = l, seg[id].r = r;
        seg[id].tag = 1;
        if(l == r)
        {
            seg[id].sum = 1;
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        pull(id);
    }

    void update(int id, int ql, int qr, int val)
    {
        int l = seg[id].l, r = seg[id].r;
        if(ql <= l && r <= qr)
        {
            seg[id].update(val);
            return;
        }
        if(ql > r || qr < l) return;
        else
        {
            push(id);
            update(id * 2, ql, qr, val);
            update(id * 2 + 1, ql, qr, val);
            pull(id);
        }
    }
    int query(int id, int ql, int qr)
    {
        int l = seg[id].l, r = seg[id].r;
        if(ql <= l && r <= qr)
            return seg[id].sum;
        if(ql > r || qr < l) return 0;
        push(id);
        return query(id * 2, ql, qr) + query(id * 2 + 1, ql, qr);
    }
} seg;

void sol() {
	cin >> n >> m;
    seg.build(1, 1, n - 1);
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        if (i < n) {
            // seg.update(1, a, b - 1, 1);
            // int ans = seg.query(1, 1, n - 1);
            cout << i << endl;
        }
            
        else {
            seg.update(1, a, b - 1, 0);
            int ans = seg.query(1, 1, n - 1);
            cout << ans << endl;

            // for (int i = 1; i <= 5; i++)
            //     cout << seg.arr[i].l << " " << seg.arr[i].r << " " << seg.arr[i].sum << endl;
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