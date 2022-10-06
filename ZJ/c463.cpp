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
int in[MAXN];
int ans = 0;

int dfs(int i, int dep) {
    int res = 0;
    for (int e: G[i]) {
        int tmp = dfs(e, dep + 1);
        cmax(res, tmp + 1);
    }
    ans += res;

    return res;
}

void sol() {
    cin >> n;
    for (int i = 1, c, a; i <= n; i++) {
        cin >> c;
        while (c--) {
            cin >> a;
            G[i].pb(a);
            in[a]++;
        }
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            cout << i << endl;
            root = i;
        }
    }
    dfs(root, 0);
    cout << ans << endl;
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