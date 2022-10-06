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
#define MAXN 200005
#define MAXM 1000005 
int n, m, q;

struct DisjointSet {
    int arr[MAXN], cnt[MAXN];

    void init() {
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int i) {
        if (arr[i] == i) return i;
        return arr[i] = find(arr[i]);
    }

    void unite(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return;
        arr[x] = y;
        cnt[y] += cnt[x];
    }
} dsu;

void sol() {
    cin >> n >> m >> q;
    dsu.init();
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        dsu.unite(a, b);
    }

    int a, b;
    while (q--) {
        cin >> a >> b;
        cout << (dsu.find(a) == dsu.find(b) ? ":)" : ":(") << endl;
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