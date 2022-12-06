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
int x[MAXN];

struct Seg_Tree {
    int arr[MAXN << 2];

    void build(int i, int l, int r) {
        if (l == r) {
            arr[i] = x[l];
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int i, int l, int r, int pos) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            arr[i] ^= 1;
            return;
        }
        int mid = (l + r) / 2;
        update(i * 2, l, mid, pos);
        update(i * 2 + 1, mid + 1, r, pos);
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    int query(int i, int l, int r, int k) {
        // cout << l << ' ' << r << endl;
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (arr[i * 2] >= k)
            return query(i * 2, l, mid, k);
        else
            return query(i * 2 + 1, mid + 1, r, k - arr[i * 2]);
    }
} Seg;

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    Seg.build(1, 1, n);

    int op, k;
    while (m--) {
        cin >> op >> k;
        k++;
        if (op == 1)
            Seg.update(1, 1, n, k);
        else
            cout << Seg.query(1, 1, n, k) - 1 << endl;
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