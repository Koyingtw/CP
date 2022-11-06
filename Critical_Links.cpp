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

struct Tarjan_Bridge {
    int low[MAXN], dep[MAXN], timestamp = 0;
    vector<pii> bridge;

    void dfs(int i, int fa) {
        dep[i] = low[i] = ++timestamp;

        for (int e: G[i]) {
            if (e == fa)
                continue;
            if (!dep[e]) {
                dfs(e, i);
                cmin(low[i], low[e]);

                if (low[e] > dep[i]) {
                    bridge.pb({min(i, e), max(i, e)});
                }
            }
            cmin(low[i], dep[e]);
        }
    }

    void main() {
        MEM(low, 0);
        MEM(dep, 0);
        timestamp = 0;
        bridge.clear();

        for (int i = 0; i < n; i++) {
            if (!dep[i])
                dfs(i, i);
        }
    }
} Bridge;

void sol() {
    while (cin >> n) {
        cin.ignore();
        for (int i = 0; i < n; i++)
            G[i].clear();

        for (int i = 0; i < n; i++) {
            stringstream ss;
            string s;
            getline(cin, s);

            for (auto &it: s)
                if (it == ')' || it == '(')
                    it = ' ';

            ss << s;
            int a, c, b;
            ss >> a;
            ss >> c;
            while (c--) {
                ss >> b;
                G[a].pb(b);
                G[b].pb(a);
            }
        }
        Bridge.main();

        sort(all(Bridge.bridge));

        cout << Bridge.bridge.size() << " critical links" << endl;
        for (auto it: Bridge.bridge)
            cout << it.F << " - " << it.S << endl;
        cout << endl;
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