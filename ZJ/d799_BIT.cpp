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
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int d[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];

    void init() {
        for (int i = 0; i <= n; i++)
            arr[i] = 0;
    }

    void update(int i, int val) {
        for (; i <= n; i += lowbit(i)) {
            arr[i] += val;
        }
    }

    int query(int i) {
        int ans = 0;
        for (; i > 0; i -= lowbit(i)) {
            ans += arr[i];
        }
        return ans;
    }
} BIT1, BIT2;

void sol() {
    cin >> n;
    BIT1.init();
    BIT2.init();
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        d[i] = x[i] - x[i - 1];
        BIT1.update(i, d[i]);
        BIT2.update(i, i * d[i]);
    }

    cin >> m;
    int v, a, b, k;
    while (m--) {
        cin >> v;
        if (v == 1 && cin >> a >> b >> k) {
            BIT1.update(a, k);
            BIT1.update(b + 1, -k);
            BIT2.update(a, a * k);
            BIT2.update(b + 1, -(b + 1) * k);
        } else if (v == 2 && cin >> a >> b) {
            auto f = [&](int i) {
                return BIT1.query(i) * (i + 1) - BIT2.query(i);
            };
            cout << f(b) - f(a - 1) << endl;
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