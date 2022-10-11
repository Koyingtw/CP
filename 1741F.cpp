#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 400005
#define MAXM 1000005 
int n, m;
int ans[MAXN];
array<int, 4> seg[MAXN];

struct Segment_Tree {
    struct Node
    {
        int tag, sum;
        void update(int val, int l, int r) {sum += val * (r - l + 1), tag += val;}
    } seg[4 * MAXN];
    void pull(int id)
    {
        seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
    }
    void push(int id, int l, int r)
    {
        if (id * 2 >= 4 * MAXN) return;
        int tag = seg[id].tag;
        int mid = (l + r) / 2;
        seg[id * 2].update(tag, l, mid);
        seg[id * 2 + 1].update(tag, mid + 1, r);
        seg[id].tag = 0;
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            seg[id].sum = seg[id].tag = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        pull(id);
        seg[id].sum = seg[id].tag = 0;
    }

    void update(int id, int l, int r, int ql, int qr, int val)
    {
        if(ql <= l && r <= qr)
        {
            seg[id].update(val, l, r);
            return;
        }
        if(ql > r || qr < l) return;
        else
        {
            int mid = (l + r) / 2;
            push(id, l, r);
            update(id * 2, l, mid, ql, qr, val);
            update(id * 2 + 1, mid + 1, r, ql, qr, val);
            pull(id);
        }
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr)
            return seg[id].sum;
        int mid = (l + r) / 2;
        push(id, l, r);
        return query(id * 2, l, mid, ql, qr) + query(id * 2 + 1, mid + 1, r, ql, qr);
    }

    pii maxposquery(int id, int l, int r, int ql, int qr) {
        int mid = (l + r) / 2;
        if (ql > r || qr < l) return {0, 0};
        push(id, l, r);

        if (seg[id].sum == 0)
            return {0, 0};
        if (ql <= l && r <= qr) {
            if (seg[id].sum && l == r)
                return {l, seg[id].sum};
            if (seg[id].sum) {
                if (seg[id * 2 + 1].sum)
                    return maxposquery(id * 2 + 1, mid + 1, r, ql, qr);
                else
                    return maxposquery(id * 2, l, mid, ql, qr);
            }
            else
                return {0, seg[id].sum};
        }

        if (query(id * 2 + 1, mid + 1, r, ql, qr))
            return maxposquery(id * 2 + 1, mid + 1, r, ql, qr);
        else
            return maxposquery(id * 2, l, mid, ql, qr);
    }

    pii minposquery(int id, int l, int r, int ql, int qr) {
        int mid = (l + r) / 2;
        if (ql > r || qr < l) return {INF, 0};
        push(id, l, r);
        if (seg[id].sum == 0)
            return {INF, 0};
        if (ql <= l && r <= qr) {
            if (l == r)
                return {l, seg[id].sum};
            if (seg[id].sum) {
                if (seg[id * 2].sum)
                    return minposquery(id * 2, l, mid, ql, qr);
                else
                    return minposquery(id * 2 + 1, mid + 1, r, ql, qr);
            }
            else
                return {INF, seg[id].sum};
        }

        if (query(id * 2, l, mid, ql, qr))
            return minposquery(id * 2, l, mid, ql, qr);
        else 
            return minposquery(id * 2 + 1, mid + 1, r, ql, qr);
    }
} ST;



void sol() {
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> seg[i][1] >> seg[i][2] >> seg[i][0];
        seg[i][3] = i;
        ans[i] = INF;
        v.pb(seg[i][1]);
        v.pb(seg[i][2]);
    }

    v.pb(-INF);
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    for (int i = 0; i < n; i++) {
        seg[i][1] = lower_bound(all(v), seg[i][1]) - v.begin();
        seg[i][2] = lower_bound(all(v), seg[i][2]) - v.begin();
    }

    sort(seg, seg + n);



    for (int t = 0; t < 2; t++) {
        ST.build(1, 0, v.size() - 1);
        queue<array<int, 4>> q;
        for (int i = 0; i < n; i++) {
            if (q.size() && q.front()[0] != seg[i][0]) {
                while (q.size()) {
                    auto [_, l, r, id] = q.front();
                    ST.update(1, 0, v.size() - 1, l, r, 1);
                    q.pop();
                }
            }

            if (ST.query(1, 0, v.size() - 1, seg[i][1], seg[i][2])) {
                ans[seg[i][3]] = 0;
            }


            int l = 1, r = seg[i][1];
            bool success = ST.query(1, 0, v.size() - 1, 1, seg[i][1]) != 0;
            if (success) {
                l = ST.maxposquery(1, 0, v.size() - 1, l, r).F;
                cmin(ans[seg[i][3]], v[seg[i][1]] - v[l]);
            }

            l = seg[i][2], r = v.size() - 1;
            success = ST.query(1, 0, v.size() - 1, seg[i][2], v.size() - 1) != 0;
            if (success) {
                r = ST.minposquery(1, 0, v.size() - 1, seg[i][2], v.size() - 1).F;
                cmin(ans[seg[i][3]], v[r] - v[seg[i][2]]);
            }
            q.push(seg[i]);
        }

        sort(seg, seg + n, [](array<int, 4> a, array<int, 4> b) {
            if (a[0] != b[0])
                return a[0] > b[0];
            else if (a[1] != b[1])
                return a[1] < b[1];
            else
                return a[2] < b[2];
        });
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}