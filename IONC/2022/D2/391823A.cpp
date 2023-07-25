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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int a[MAXN], b[MAXN];
int ans[MAXN];

void cal() {
    ans[1] = ans[2] = 1;
    for (int i = 3; i <= n; i++) {
        ans[i] = a[i] * ans[i - 2] + b[i] * ans[i - 1];
        ans[i] %= P;
    }
    cout << ans[n] << endl;
}

void sub1() {
    int id, A, B;
    while (m--) {
        cin >> id >> A >> B;
        a[id] = A;
        b[id] = B;
        cal();
    }
}

struct segment_tree {
    int seg[MAXN << 2];

    void build(int i, int l, int r) {
        if (l == r) {
            seg[i] = b[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        seg[i] = seg[i << 1] * seg[i << 1 | 1];
        seg[i] %= P;
    }

    void update(int i, int l, int r, int pos) {
        if (l == r) {
            seg[i] = b[pos];
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(i << 1, l, mid, pos);
        else
            update(i << 1 | 1, mid + 1, r, pos);
        seg[i] = seg[i << 1] * seg[i << 1 | 1];
        seg[i] %= P;
    }
} seg;

void sol() {
	cin >> n >> m >> P;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if (n <= 1000 && m <= 1000) {
        sub1();
    }
    else {
        seg.build(1, 3, n);
        int id, A, B;
        while (m--) {
            cin >> id >> A >> B;
            a[id] = A;
            b[id] = B;
            if (id > 2)
                seg.update(1, 3, n, id);
            cout << seg.seg[1] % P << endl;
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