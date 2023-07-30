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
int x[MAXN], y[MAXN];
pii pos[MAXN];

struct Segment_Tree {
    struct Node {
        int sum, tag;
        
        void update(int l, int r, int val) {
            sum += val * (r - l + 1);
            tag += val;
        }
    } arr[MAXN << 2];

    void push(int i, int l, int r) {
        if (arr[i].tag && l != r) {
            arr[i << 1].update(l, r, arr[i].tag);
            arr[i << 1 | 1].update(l, r, arr[i].tag);
            arr[i].tag = 0;
        }
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql) 
            return;
        if (ql <= l && r <= qr) {
            arr[i].update(l, r, val);
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        update(i << 1, l, mid, ql, qr, val);
        update(i << 1 | 1, mid + 1, r, ql, qr, val);
        arr[i].sum = arr[i << 1].sum + arr[i << 1 | 1].sum;
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) 
            return 0;
        if (ql <= l && r <= qr) {
            return arr[i].sum;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        return query(i << 1, l, mid, ql, qr) + query(i << 1 | 1, mid + 1, r, ql, qr);
    }
} seg;

void sol() {
    cin >> n;

    MEM(pos, 0x3f);
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (pos[x[i]].F == 0)    
            pos[x[i]].F = i;
        else
            pos[x[i]].S = i;
        if (pos[x[i]].F > pos[x[i]].S)
            swap(pos[x[i]].F, pos[x[i]].S);
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        if (pos[y[i]].F == 0)    
            pos[y[i]].F = i;
        else
            pos[y[i]].S = i;
        if (pos[y[i]].F > pos[y[i]].S)
            swap(pos[y[i]].F, pos[y[i]].S);
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << pos[i].F << ' ' << pos[i].S << endl;
        int l = pos[i].S, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (seg.query(1, 1, n, pos[i].S, mid) != mid - pos[i].S + 1) {
                r = mid - 1;
            } 
            else {
                l = mid;
            }
        }
        int start = l + 1;
        l = l + 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (seg.query(1, 1, n, pos[i].S + 1, mid) != 0) {
                r = mid - 1;
            } 
            else {
                l = mid;
            }
        }
        int len = (l - start + 1);
        if (seg.query(1, 1, n, pos[i].S + 1, l) == 0 && l <= n) {
            ans += (len + 1) * len / 2;
            cout << start << ' ' << l << endl;
        }

        l = 1, r = pos[i].F;
        while (l < r) {
            int mid = (l + r) / 2;
            if (seg.query(1, 1, n, mid, pos[i].F) != pos[i].F - mid + 1) {
                l = mid + 1;
            } 
            else {
                r = mid;
            }
        }

        start = r - 1;
        // cout << r << endl;
        l = 1, r = r - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (seg.query(1, 1, n, mid, pos[i].F - 1) != 0) {
                l = mid + 1;
            } 
            else {
                r = mid;
            }
        }
        len = (start - r + 1);

        if (seg.query(1, 1, n, r, start) == 0 && start) {
            ans += (len + 1) * len / 2;
            cout << "L " << r << ' ' << start << endl;
            cout << seg.query(1, 1, n, r, start) << endl;
        }
        seg.update(1, 1, n, 1, pos[i].F - 1, 1);
        seg.update(1, 1, n, pos[i].S + 1, n, 1);
    }
    cout << ans << endl;
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