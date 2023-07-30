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
#define MAXN 35005
#define MAXM 1000005 
int n, k;
int dp[MAXN];
int x[MAXN];
int lst[MAXN];
int prv[MAXN];

struct Segment_Tree {
    struct Node {
        int mx, tag;
        
        void update(int l, int r, int val) {
            mx += val;
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
        arr[i].mx = max(arr[i << 1].mx, arr[i << 1 | 1].mx);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) 
            return 0;
        if (ql <= l && r <= qr) {
            return arr[i].mx;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        int q1 = query(i << 1, l, mid, ql, qr);
        int q2 = query(i << 1 | 1, mid + 1, r, ql, qr);
        return max(q1, q2);
    }

    void init(int i, int l, int r) {
        arr[i].tag = 0;
        if (l == r) {
            arr[i].mx = dp[l];
            return;
        }
        int mid = (l + r) / 2;
        init(i * 2, l, mid);
        init(i * 2 + 1, mid + 1, r);
        arr[i].mx = max(arr[i * 2].mx, arr[i * 2 + 1].mx);
    }
} seg;

void sol() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        prv[i] = lst[x[i]];
        lst[x[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
        seg.init(1, 0, n);
        for (int j = 1; j <= n; j++) {
            seg.update(1, 0, n, prv[j], j - 1, 1);
            dp[j] = seg.query(1, 0, n, 0, j - 1);
        }
    }
    cout << dp[n] << endl;
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