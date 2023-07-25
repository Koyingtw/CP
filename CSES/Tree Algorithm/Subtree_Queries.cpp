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
vector<int> x(MAXN), y(MAXN);
vector<vector<int>> G(MAXN, vector<int>());


struct HLD {
    struct Info {
        int sub, mxsub, dep, fa, root, id;
    } arr[MAXN];

    int index = 0;

    void find_son(int i, int fa) {
        pii mx(0, i);
        arr[i].sub = 1;
        for (auto it: G[i]) if (it != fa) {
            arr[it].dep = arr[i].dep + 1;
            arr[it].fa = i;
            find_son(it, i);
            cmax(mx, pii(arr[it].sub, it));
            arr[i].sub += arr[it].sub;    
        }
        arr[i].mxsub = mx.S;
    }

    void build(int i, int root) {
        arr[i].root = root;
        arr[i].id = ++index;
        y[arr[i].id] = x[i];
        
        if (arr[i].mxsub != i) {
            build(arr[i].mxsub, root);
            y[arr[i].id] += y[arr[arr[i].mxsub].id];
        }
        
        for (auto it: G[i]) if (it != arr[i].fa && it != arr[i].mxsub) {
            build(it, it);
            y[arr[i].id] += y[arr[it].id];
        }
    }

    vector<pii> jump(int a, int b) { // from a to b (dep(a) > dep(b))
        vector<pii> ret;
        while (arr[a].root != arr[b].root) {
            ret.pb({arr[arr[a].root].id, arr[a].id});
            a = arr[arr[a].root].fa;
        }
        ret.pb({arr[b].id, arr[a].id});
        return ret;
    }
} HLD;

struct Fenwick_Tree {
    int arr[MAXN << 1];

    void update(int i, int val) {
        for (; i < MAXN * 2; i += lowbit(i))
            arr[i] += val;
    }

    int query(int i) {
        int ret = 0;
        for (; i; i -= lowbit(i))
            ret += arr[i];
        return ret;
    }
} BIT;


void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    HLD.find_son(1, 1);
    HLD.build(1, 1);


    for (int i = 1; i <= n; i++) {
        BIT.update(i, y[i] - y[i - 1]);
    }

    int op, a, b;
    while (m--) {
        cin >> op;
        if (op == 1 && cin >> a >> b) {
            auto v = HLD.jump(a, 1);
            for (auto it: v) {
                BIT.update(it.F, b - x[a]);
                BIT.update(it.S + 1, -(b - x[a]));
            }
            x[a] = b;
        }
        else if (op == 2 && cin >> a) {
            cout << BIT.query(HLD.arr[a].id) << endl;
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