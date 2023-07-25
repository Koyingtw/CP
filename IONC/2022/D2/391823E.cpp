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
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 20005
#define MAXM 1000005 
int n, m;
vector<tuple<int, int, int>> E;

struct disjoint_set {
    int arr[MAXN << 1], cnt[MAXN << 1];

    void init() {
        for (int i = 1; i <= 2 * n; i++) {
            arr[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int x) {
        if (arr[x] == x) return x;
        return arr[x] = find(arr[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (cnt[x] < cnt[y]) swap(x, y);
        arr[x] = y;
        cnt[y] += cnt[x];
    }
} dsu;

vector<int> G[MAXN];

void sol() {
	cin >> n >> m;
    dsu.init();

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x].pb(y);
        G[y].pb(x);
        E.pb({z, x, y});
    }
    sort(all(E), greater<tuple<int, int, int>>());


    for (int i = 0; i < m; i++) {
        int x, y, z;
        tie(z, x, y) = E[i];

        dsu.merge(x, y + n);
        dsu.merge(x + n, y);

        if (dsu.find(x) == dsu.find(x + n) || dsu.find(y) == dsu.find(y + n)) {
            cout << z << endl;
            return;
        }
    }
    cout << 0 << endl;
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