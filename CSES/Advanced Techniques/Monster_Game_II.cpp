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
int s[MAXN], f[MAXN], dp[MAXN];

struct Line {
    int a, b;
    int operator ()(const int &_x) {
        return a * _x + b;
    }

    int operator *(const Line &rhs) {
        return (b - rhs.b) / (rhs.a - a);
    }
};

struct LeeChao_SegTree {
    Line arr[MAXM << 2];

    void init() {
        for (int i = 0; i < (MAXM << 2); i++) {
            arr[i] = {m, 0};
        }
    }

    void insert(int i, int l, int r, Line x) {
        if (l == r) {
            if (x(l) < arr[i](l)) {
                arr[i] = x;
            }
            return;
        }

        if (arr[i].a > x.a) {
            swap(arr[i], x);
        }

        int mid = (l + r) / 2;

        if (x(mid) > arr[i](mid)) {
            insert(i * 2, l, mid, x);
        }
        else {
            swap(arr[i], x);
            insert(i * 2 + 1, mid + 1, r, x);
        }
    }

    int query(int i, int l, int r, int pos) {
        if (l == r)
            return arr[i](pos);
        int mid = (l + r) / 2;
        int res;
        if (pos <= mid) {
            res = query(i * 2, l, mid, pos);
        }
        else {
            res = query(i * 2 + 1, mid + 1, r, pos);
        }
        return min(res, arr[i](pos));
    }
} Seg;

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> f[i];

    Seg.init();

    for (int i = 1; i <= n; i++) {
        dp[i] = Seg.query(1, 1, (int)1e6, s[i]);
        Seg.insert(1, 1, (int)1e6, {f[i], dp[i]});    }

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