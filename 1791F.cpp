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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
// const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int a[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];

    void init() {
        for (int i = 0; i <= n + 1; i++)
            arr[i] = 0;
    }

    void update(int i, int val) {
        for (; i <= n + 1; i += lowbit(i))
            arr[i] += val;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i))
            res += arr[i];
        return res;
    }
} BIT;

int upd(int i) {
    int tmp = 0;
    while (i) {
        tmp += i % 10;
        i /= 10;
    }
    return tmp;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    BIT.init();

    int op, l, r;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            BIT.update(l, 1);
            BIT.update(r + 1, -1);
        }
        else {
            cin >> l;
            int qry = BIT.query(l);
            BIT.update(l, -qry);
            BIT.update(l + 1, qry);

            while (qry-- && a[l] >= 10) {
                a[l] = upd(a[l]);
            }

            cout << a[l] << endl;
        }
    }
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