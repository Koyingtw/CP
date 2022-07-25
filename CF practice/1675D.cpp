#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
vector<vector<int>> ans;

void init() {
    for (int i = 0; i <= n; i++)
        G[i].clear();
    ans.clear();
}

int dfs(int i) {
    if (G[i].size() == 0) {
        ans.pb({i});
        return (int)(ans.size() - 1);
    }

    vector<int> res;
    for (int e: G[i]) {
        res.pb(dfs(e));
    }
    sort(all(res), [&](const int& a, const int& b) {
        return ans[a].size() < ans[b].size();
    });

    ans[res.back()].pb(i);
    return res.back();
}

void sol() {
    cin >> n;
    init();

    int root = 0;

    for (int i = 1, fa; i <= n; i++) {
        cin >> fa;
        if (fa == i)
            root = i;
        else
            G[fa].push_back(i);
    }

    dfs(root);

    cout << ans.size() << endl;
    for (auto &it: ans) {
        cout << it.size() << endl;
        reverse(all(it));
        for (auto &node: it)
            cout << node << " ";
        cout << endl;
    }
    cout << endl;
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
