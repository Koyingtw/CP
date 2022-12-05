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
int n, m;
vector<int> G[MAXN];

struct Euler_Tour {
    int tt = 0;
    int in[MAXN], out[MAXN], d[MAXN], sz[MAXN];
    int arr[25][MAXN];

    bool isAnc(int i, int j) {
        return (in[i] <= in[j] && out[i] >= out[j]);
    }

    void init() {
        out[0] = INF;
    }

    void dfs(int i, int dep) {
        in[i] = ++tt;
        d[i] = dep;
        for (int e: G[i]) {
            if (!in[e]) {
                arr[0][e] = i;
                dfs(e, dep + 1);
                sz[i] += sz[e];
            }
        }
        out[i] = ++tt;
        sz[i]++;
    }

    void buildST() {        
        for (int i = 1; i <= __lg(n); i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = arr[i - 1][arr[i - 1][j]];
            }
        }
    }
} ET;

struct LCA {
    int find(int a, int b) {
        if (ET.in[a] > ET.in[b])
            swap(a, b);

        if (ET.isAnc(a, b)) {
            return a;
        }

        for (int i = 20; i >= 0; i--) {
            if (!ET.isAnc(ET.arr[i][a], b)) {
                a = ET.arr[i][a];
            }
        }

        return ET.arr[0][a];
    }

    int mv(int a, int dis) {
        for (int i = 20; i >= 0; i--) {
            if (dis >= (1 << i)) {
                a = ET.arr[i][a];
                dis -= (1 << i);
            }
        }
        return a;
    }
} LCA;

void sol() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    ET.init();
    ET.dfs(1, 1);
    ET.buildST();

    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << n << endl;
            continue;
        }

        int lca = LCA.find(a, b);
        int disa = ET.d[a] - ET.d[lca];
        int disb = ET.d[b] - ET.d[lca];

        if ((disa + disb) % 2 == 0) {
            int mid = LCA.mv((disa > disb) ? a : b, (disa + disb) / 2);
            int ans = n;

            if (ET.isAnc(mid, a))
                ans -= ET.sz[LCA.mv(a, (disa + disb) / 2 - 1)];
            else
                ans -= n - ET.sz[mid];

            if (ET.isAnc(mid, b))
                ans -= ET.sz[LCA.mv(b, (disa + disb) / 2 - 1)];
            else
                ans -= n - ET.sz[mid];
                
            cout << ans << endl;
        }
        else {
            cout << 0 << endl;
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