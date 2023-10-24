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
struct Fenwick_Tree {
    int arr[MAXN];

    void init() {
        for (int i = 0; i <= n; i++)
            arr[i] = 0;
    }

    void update(int i, int val) {
        for (; i <= n; i += lowbit(i))
            arr[i] += val;
    }

    int query(int i) {
        int ret = 0;
        for (; i; i -= lowbit(i))
            ret += arr[i];
        return ret;
    }
} BIT;

int dp[MAXN][2];

void sol() {
    cin >> n;
    // BIT.init();

    // int oddsum = 0, evensum = 0;
    int sum = 0;
    priority_queue<pii, vector<pii>, less<pii>> pq;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        // if (i % 2)
        //     odd.push(x[i]);
        // else
        //     even.push(x[i]);
        // pq.push(pii(x[i], i));
        // BIT.update(i, 1);
        // dp[i][0] = dp[i][1] = -INFLL;
        if (x[i] >= 0)
            sum += x[i];
    }

    if (x[1] >= 0) {
        cout << sum << endl;
        return;
    }

    int ans = 0;
    sum = 0;
    for (int i = n; i; i--) {
        cmax(ans, sum + x[i] * (i % 2));
        // cout << sum + x[i] << ' ';
        if (x[i] >= 0) {
            sum += x[i];
        }
    }
    cout << ans << endl;
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