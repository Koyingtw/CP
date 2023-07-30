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
bitset<MAXN> blue;
int dp[MAXN];

struct Node {
    int mn;

    void update(int val) {
        cmin(mn, val);
    }
    Node(): mn(INF) {}

    Node operator +(const Node rhs) {
        Node ret;
        ret.mn = min(mn, rhs.mn);
        return ret;
    }
};

template<typename T>
struct Segment_Tree {
    vector<T> arr;

    void init() {
        arr.resize((n + 1) << 2, T());
    }

    void update(int pos, int val, int i = 1, int l = 0, int r = n) {
        if (l == r) {
            arr[i].update(val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(pos, val, i * 2, l, mid);
        else
            update(pos, val, i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    T query(int ql, int qr, int i = 1, int l = 0, int r = n) {
        if (ql <= l && r <= qr)
            return arr[i];
        if (l > qr || r < ql)
            return T();
        int mid = (l + r) / 2;
        return query(ql, qr, i * 2, l, mid) +
            query(ql, qr, i * 2 + 1, mid + 1, r);
    }
};

Segment_Tree<Node> seg;
int pre[MAXN];

void sol() {
    cin >> n;
    seg.init();
    int ans = 0;

    blue[0] = false;
    for (int i = 1; i <= n; i++) {
        blue[i] = true;
        cin >> x[i];
        pre[i] = pre[i - 1] + (x[i] != 0);
    }

    // for (int i = 1; i <= n; i++)
    //     cin >> x[i];
    seg.update(0, 0);
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            dp[i] = seg.query(i - 1, n).mn + 1;
            seg.update(i, dp[i]);
        }
        else if (x[i] == 1) {
            // to right;
            int l = i, r = n;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (pre[mid] - pre[i - 1] == (mid - i + 1)) 
                    l = mid;
                else
                    r = mid - 1;
            }
            dp[i] = seg.query(i - 1, n).mn + 1;
            seg.update(min(l + 1, n), dp[i]);
            // cout << l << ' ' << dp[i] << endl;


            l = 1, r = i;
            // to left
            while (l < r) {
                int mid = (l + r) / 2;
                if (pre[i] - pre[mid - 1] == (i - mid + 1))
                    r = mid;
                else
                    l = mid + 1;
            }
            dp[i] = seg.query(max(r - 2, 0), n).mn + 1;
            // cout << r << ' ' << dp[i] << endl;
            seg.update(i, dp[i]);

        }
        else {
            int L, R;
            int l = i, r = n;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (pre[mid] - pre[i - 1] == (mid - i + 1)) 
                    l = mid;
                else
                    r = mid - 1;
            }
            R = l;


            l = 1, r = i;
            // to left
            while (l < r) {
                int mid = (l + r) / 2;
                if (pre[i] - pre[mid - 1] == (i - mid + 1))
                    r = mid;
                else
                    l = mid + 1;
            }
            L = r;

            dp[i] = seg.query(max(L - 2, 0), n).mn + 1;
            seg.update(min(n, R + 1), dp[i]);
        }
    }



    cout << seg.query(n, n).mn << endl;
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