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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, c, d;
int dp[MAXN];
array<int, 4> info[MAXN];

struct Line {
    int a, b;
    int operator() (int x) {
        return a * x + b;
    }
};

struct LeeChao_SegTree {
    Line arr[MAXN << 2];

    void init() {
        for (int i = 0; i < (MAXN << 2); i++) {
            arr[i] = {0, c};
        }
    }

    void update(int i, int l, int r, int ql, int qr, Line x) {
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr)
            insert(i, l, r, x);
        
        int mid = (l + r) / 2;
        update(i * 2, l, mid, ql, qr, x);
        update(i * 2 + 1, mid + 1, r, ql, qr, x);
    }

    void insert(int i, int l, int r, Line x) {
        if (l == r) {
            if (x(info[l][0]) > arr[i](info[l][0]))
                arr[i] = x;
            return;
        }

        int mid = (l + r) / 2;
        if (arr[i].a > x.a)
            swap(arr[i], x);
        
        if (x(info[mid][0]) > arr[i](info[mid][0])) {
            swap(arr[i], x);
            insert(i * 2, l, mid, x);
        }
        else {
            insert(i * 2 + 1, mid + 1, r, x);
        }
    }

    int query(int i, int l, int r, int pos, int day) {
        if (l == r)
            return arr[i](day);
        int mid = (l + r) / 2, res;

        if (pos <= mid)
            res = query(i * 2, l, mid, pos, day);
        else
            res = query(i * 2 + 1, mid + 1, r, pos, day);
        return max(res, arr[i](day));
    }
} Seg;

void sol() {
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++)
            cin >> info[i][j];
    }

    Seg.init();

    sort(info + 1, info + n + 1);
    info[n + 1] = {d + 1, 0, 0, 0};

    for (int i = 1; i <= n + 1; i++) {
        auto [D, P, R, G] = info[i]; // D P R G

        dp[i] = Seg.query(1, 1, n + 1, i, D) - P;

        if (dp[i] >= 0)
            Seg.insert(1, 1, n + 1, {G, dp[i] - (D + 1) * G + R});
    }
    cout << dp[n + 1] << endl;
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